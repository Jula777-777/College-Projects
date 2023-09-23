'use strict'

/*
|--------------------------------------------------------------------------
| Routes
|--------------------------------------------------------------------------
|
| Http routes are entry points to your web application. You can create
| routes for different URLs and bind Controller actions to them.
|
| A complete guide on routing is available here.
| http://adonisjs.com/docs/4.1/routing
|
*/

/** @type {typeof import('@adonisjs/framework/src/Route/Manager')} */
const Route = use('Route')

Route.get("/", ({request, response}) => {
  response.send("Welcome to my Backend Application")
})

//Dev requests
Route.post('import','ImportController.import')
Route.post('import/multi','ImportMultiController.importMulti')
Route.post('auth/dev-register', 'UserController.devRegister')
Route.get("/requests", "ApprovalController.listRequests");//delete this later
Route.get('auth/listUsers', 'UserController.listUsers');
Route.get('auth/listRoles', 'DevController.listRoles');


//All users can use these controllers
Route.group(() => {
  Route.post('auth/register', 'UserController.register');
  Route.post('auth/login', 'UserController.login');

  //Route.post("/approval/:id", "ApprovalController.approveRegistration");
})
  .prefix('api/v0');

  //Routes all authenticated users can access
  Route.group(() => {
    Route.get("/assistant/scheduler", "AssistantController.scheduler"); //don't know what route.xxx should be
    Route.post("/assistant/edit", "AssistantController.edit"); //check what route.xxx should be 
  }).middleware("auth")
    .prefix('api/v0');
  
  //Routes admin and root users can access
  Route.group(() => {
    Route.post("/setup/add", "SetupController.setup"); //check what route.xxx should be
    Route.post("/setup/addInstructor", "SetupController.addInstructor");
    Route.post("/setup/addSection", "SetupController.addSection");
    Route.post("/setup/addCourse", "SetupController.addCourse");
    Route.post("/setup/modify-section/:id", "SetupController.modifySection");
    Route.post("/setup/modify-instructor/:id", "SetupController.modifyInstructor");
    Route.post("/setup/modify-course/:CRN", "SetupController.modifyCourse");
    Route.delete("/setup/delete-section/:id", "SetupController.deleteSection");
    Route.delete("/setup/delete-instructor/:id", "SetupController.deleteInstructor");
    Route.delete("/setup/delete-course/:CRN", "SetupController.deleteCourse");
    Route.get("/setup/sections/", "SetupController.listSections");
    Route.get("/setup/instructors/", "SetupController.listInstructors");
    Route.get("/setup/courses/", "SetupController.listCourses");
  }).middleware(["auth", "admin"])
    .prefix('api/v0');

  //Routes ROOT can access  
  Route.group(() => {
    Route.get("/requests", "ApprovalController.listRequests"); //Endpoint to grab list of requests
    Route.post("/approval/:id", "ApprovalController.approveRegistration"); //Endpoint to post approve/deny requests
    Route.post("/setup/root-add", "SetupController.setup"); //check what route.xxx should be
  }).middleware("auth", "root")
    .prefix('api/v0');
