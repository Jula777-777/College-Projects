<style>
  .tab {
  overflow: hidden;
  border: 1px solid #ccc none;
  background-color: #f1f1f1;
  display: inline-block;
}

/* Style the buttons inside the tab */
.tab button {
  background-color: inherit;
  border: none;
  outline: none;
  cursor: pointer;
  padding: 14px 16px;
  transition: 0.3s;
  font-size: 17px;
}

/* Change background color of buttons on hover */
.tab button:hover {
  background-color: #ddd;
}

/* Create an active/current tablink class */
.tab button.active {
  background-color: #ccc;
}

/* Style the tab content */
.tabcontent {
  display: none;
  padding-bottom: 50px;
}
</style>
<template>
<body>
  <div style="background-color:#640309;">
        <img alt="UALRlogo" src="../assets/ualr.png">
    </div>
  <div class="title" style="padding: 25px; padding-left: 35px; width: 30%;">  
    <h3 style="">Setup</h3>
    <hr>
  </div>
 <center>  

<div class="tab">
    <button style="border-left: 1px solid #ccc;" id="openInstructors" class="tablinks" @click="openTab('openInstructors', 'InstructorsTab')">Instructors</button>
    <button style="border-left: 1px solid #ccc; border-right: 1px solid #ccc;;" id="openCourses" class="tablinks" @click="openTab('openCourses', 'CoursesTab')">Courses</button>
    <button style="border-right: 1px solid #ccc;;" id="openSection" class="tablinks" @click="openTab('openSection', 'SectionsTab')">Sections</button>
</div>
<br>

<div id="InstructorsTab" class="tabcontent">
  <dialog id="addInstructorDialogBox">
    <p>
      Input the data for the new instructor:
    </p>
    <form method="dialog" @submit="onAddInstructor()">
      <div class="form-group">
        <label for="add_last_name">Last Name</label>
        <input type="text" class="form-control" name="add_last_name" v-model="add_last_name" required/>
      </div>
      <div class="form-group">
        <label for="add_max_course_load">Max Course Load</label>
        <input type="number" class="form-control" name="add_max_course_load" v-model="add_max_course_load" min="0" max="10" required/>
      </div>
      <div class="form-group">
        <label for="add_instructor_discipline_area1">Discipline Area 1</label>
        <br>
        <select v-model="add_instructor_discipline_area1" name="add_instructor_discipline_area1">
          <option value="None">None</option>
          <option value="Programming-C++">Programming-C++</option>
          <option value="Programming-Python">Programming-Python</option>
          <option value="Software Engineering">Software Engineering</option>
          <option value="Software Development Methodologies">Software Development Methodologies</option>
          <option value="Game Development">Game Development</option>
          <option value="Data Structures and Algorithms">Data Structures and Algorithms</option>
          <option value="Computer Organization">Computer Organization</option>
          <option value="Operating Systems">Operating Systems</option>
          <option value="Programming Languages">Programming Languages</option>
          <option value="Cybersecurity">Cybersecurity</option>
          <option value="Mobile Applications">Mobile Applications</option>
          <option value="Artificial Intelligence">Artificial Intelligence</option>
          <option value="Networks">Networks</option>
          <option value="Theory of Computation">Theory of Computation</option>
          <option value="Parallel and Distributed Systems">Parallel and Distributed Systems</option>
          <option value="Virtual Reality">Virtual Reality</option>
          <option value="Hardware Designs">Hardware Designs</option>
        </select>
      </div>
      <div class="form-group">
        <label for="add_instructor_discipline_area2">Discipline Area 2</label>
        <br>
        <select v-model="add_instructor_discipline_area2" name="add_instructor_discipline_area2">
          <option value="None">None</option>
          <option value="Programming-C++">Programming-C++</option>
          <option value="Programming-Python">Programming-Python</option>
          <option value="Software Engineering">Software Engineering</option>
          <option value="Software Development Methodologies">Software Development Methodologies</option>
          <option value="Game Development">Game Development</option>
          <option value="Data Structures and Algorithms">Data Structures and Algorithms</option>
          <option value="Computer Organization">Computer Organization</option>
          <option value="Operating Systems">Operating Systems</option>
          <option value="Programming Languages">Programming Languages</option>
          <option value="Cybersecurity">Cybersecurity</option>
          <option value="Mobile Applications">Mobile Applications</option>
          <option value="Artificial Intelligence">Artificial Intelligence</option>
          <option value="Networks">Networks</option>
          <option value="Theory of Computation">Theory of Computation</option>
          <option value="Parallel and Distributed Systems">Parallel and Distributed Systems</option>
          <option value="Virtual Reality">Virtual Reality</option>
          <option value="Hardware Designs">Hardware Designs</option>
        </select>
      </div>
      <div class="form-group">
        <label for="add_instructor_discipline_area3">Discipline Area 3</label>
        <br>
        <select v-model="add_instructor_discipline_area3" name="add_instructor_discipline_area3">
          <option value="None">None</option>
          <option value="Programming-C++">Programming-C++</option>
          <option value="Programming-Python">Programming-Python</option>
          <option value="Software Engineering">Software Engineering</option>
          <option value="Software Development Methodologies">Software Development Methodologies</option>
          <option value="Game Development">Game Development</option>
          <option value="Data Structures and Algorithms">Data Structures and Algorithms</option>
          <option value="Computer Organization">Computer Organization</option>
          <option value="Operating Systems">Operating Systems</option>
          <option value="Programming Languages">Programming Languages</option>
          <option value="Cybersecurity">Cybersecurity</option>
          <option value="Mobile Applications">Mobile Applications</option>
          <option value="Artificial Intelligence">Artificial Intelligence</option>
          <option value="Networks">Networks</option>
          <option value="Theory of Computation">Theory of Computation</option>
          <option value="Parallel and Distributed Systems">Parallel and Distributed Systems</option>
          <option value="Virtual Reality">Virtual Reality</option>
          <option value="Hardware Designs">Hardware Designs</option>
        </select>
      </div>
      <div class="form-group">
        <label for="add_instructor_discipline_area4">Discipline Area 4</label>
        <br>
        <select v-model="add_instructor_discipline_area4" name="add_instructor_discipline_area4">
          <option value="None">None</option>
          <option value="Programming-C++">Programming-C++</option>
          <option value="Programming-Python">Programming-Python</option>
          <option value="Software Engineering">Software Engineering</option>
          <option value="Software Development Methodologies">Software Development Methodologies</option>
          <option value="Game Development">Game Development</option>
          <option value="Data Structures and Algorithms">Data Structures and Algorithms</option>
          <option value="Computer Organization">Computer Organization</option>
          <option value="Operating Systems">Operating Systems</option>
          <option value="Programming Languages">Programming Languages</option>
          <option value="Cybersecurity">Cybersecurity</option>
          <option value="Mobile Applications">Mobile Applications</option>
          <option value="Artificial Intelligence">Artificial Intelligence</option>
          <option value="Networks">Networks</option>
          <option value="Theory of Computation">Theory of Computation</option>
          <option value="Parallel and Distributed Systems">Parallel and Distributed Systems</option>
          <option value="Virtual Reality">Virtual Reality</option>
          <option value="Hardware Designs">Hardware Designs</option>
        </select>
      </div>
      <button type="submit" class="btn btn-primary" style="margin: 10px;" value="submit">Submit</button>
      <button type="button" class="btn btn-primary" style="background-color: red; border-color: red" onclick="let dialogBox = document.getElementById('addInstructorDialogBox'); dialogBox.close()">Cancel</button>
    </form>
  </dialog>

  <dialog id="modifyInstructorDialogBox">
    <p>
      Input the new data for the instructor:
    </p>
    <form method="dialog" @submit="onModifyInstructor()">
      <div class="form-group">
        <label for="modify_last_name">Last Name</label>
        <input type="text" class="form-control" name="modify_last_name" id ="modify_last_name" required/>
      </div>
      <div class="form-group">
        <label for="modify_max_course_load">Max Course Load</label>
        <input type="number" class="form-control" name="modify_max_course_load" id="modify_max_course_load" min="0" max="10" required/>
      </div>
      <div class="form-group">
        <label for="modify_instructor_discipline_area1">Discipline Area 1</label>
        <br>
        <select id="modify_instructor_discipline_area1" name="modify_instructor_discipline_area1">
          <option value="None">None</option>
          <option value="Programming-C++">Programming-C++</option>
          <option value="Programming-Python">Programming-Python</option>
          <option value="Software Engineering">Software Engineering</option>
          <option value="Software Development Methodologies">Software Development Methodologies</option>
          <option value="Game Development">Game Development</option>
          <option value="Data Structures and Algorithms">Data Structures and Algorithms</option>
          <option value="Computer Organization">Computer Organization</option>
          <option value="Operating Systems">Operating Systems</option>
          <option value="Programming Languages">Programming Languages</option>
          <option value="Cybersecurity">Cybersecurity</option>
          <option value="Mobile Applications">Mobile Applications</option>
          <option value="Artificial Intelligence">Artificial Intelligence</option>
          <option value="Networks">Networks</option>
          <option value="Theory of Computation">Theory of Computation</option>
          <option value="Parallel and Distributed Systems">Parallel and Distributed Systems</option>
          <option value="Virtual Reality">Virtual Reality</option>
          <option value="Hardware Designs">Hardware Designs</option>
        </select>
      </div>
      <div class="form-group">
        <label for="modify_instructor_discipline_area2">Discipline Area 2</label>
        <br>
        <select id="modify_instructor_discipline_area2" name="modify_instructor_discipline_area2">
          <option value="None">None</option>
          <option value="Programming-C++">Programming-C++</option>
          <option value="Programming-Python">Programming-Python</option>
          <option value="Software Engineering">Software Engineering</option>
          <option value="Software Development Methodologies">Software Development Methodologies</option>
          <option value="Game Development">Game Development</option>
          <option value="Data Structures and Algorithms">Data Structures and Algorithms</option>
          <option value="Computer Organization">Computer Organization</option>
          <option value="Operating Systems">Operating Systems</option>
          <option value="Programming Languages">Programming Languages</option>
          <option value="Cybersecurity">Cybersecurity</option>
          <option value="Mobile Applications">Mobile Applications</option>
          <option value="Artificial Intelligence">Artificial Intelligence</option>
          <option value="Networks">Networks</option>
          <option value="Theory of Computation">Theory of Computation</option>
          <option value="Parallel and Distributed Systems">Parallel and Distributed Systems</option>
          <option value="Virtual Reality">Virtual Reality</option>
          <option value="Hardware Designs">Hardware Designs</option>
        </select>
      </div>
      <div class="form-group">
        <label for="modify_instructor_discipline_area3">Discipline Area 3</label>
        <br>
        <select id="modify_instructor_discipline_area3" name="modify_instructor_discipline_area3">
          <option value="None">None</option>
          <option value="Programming-C++">Programming-C++</option>
          <option value="Programming-Python">Programming-Python</option>
          <option value="Software Engineering">Software Engineering</option>
          <option value="Software Development Methodologies">Software Development Methodologies</option>
          <option value="Game Development">Game Development</option>
          <option value="Data Structures and Algorithms">Data Structures and Algorithms</option>
          <option value="Computer Organization">Computer Organization</option>
          <option value="Operating Systems">Operating Systems</option>
          <option value="Programming Languages">Programming Languages</option>
          <option value="Cybersecurity">Cybersecurity</option>
          <option value="Mobile Applications">Mobile Applications</option>
          <option value="Artificial Intelligence">Artificial Intelligence</option>
          <option value="Networks">Networks</option>
          <option value="Theory of Computation">Theory of Computation</option>
          <option value="Parallel and Distributed Systems">Parallel and Distributed Systems</option>
          <option value="Virtual Reality">Virtual Reality</option>
          <option value="Hardware Designs">Hardware Designs</option>
        </select>
      </div>
      <div class="form-group">
        <label for="modify_instructor_discipline_area4">Discipline Area 4</label>
        <br>
        <select id="modify_instructor_discipline_area4" name="modify_instructor_discipline_area4">
          <option value="None">None</option>
          <option value="Programming-C++">Programming-C++</option>
          <option value="Programming-Python">Programming-Python</option>
          <option value="Software Engineering">Software Engineering</option>
          <option value="Software Development Methodologies">Software Development Methodologies</option>
          <option value="Game Development">Game Development</option>
          <option value="Data Structures and Algorithms">Data Structures and Algorithms</option>
          <option value="Computer Organization">Computer Organization</option>
          <option value="Operating Systems">Operating Systems</option>
          <option value="Programming Languages">Programming Languages</option>
          <option value="Cybersecurity">Cybersecurity</option>
          <option value="Mobile Applications">Mobile Applications</option>
          <option value="Artificial Intelligence">Artificial Intelligence</option>
          <option value="Networks">Networks</option>
          <option value="Theory of Computation">Theory of Computation</option>
          <option value="Parallel and Distributed Systems">Parallel and Distributed Systems</option>
          <option value="Virtual Reality">Virtual Reality</option>
          <option value="Hardware Designs">Hardware Designs</option>
        </select>
      </div>
      <button type="submit" class="btn btn-primary" style="margin: 10px;" value="submit">Submit</button>
      <button type="button" class="btn btn-primary" style="background-color: red; border-color: red" onclick="let dialogBox = document.getElementById('modifyInstructorDialogBox'); dialogBox.close()">Cancel</button>
    </form>
  </dialog>
  <div style="padding-bottom: 25px;">
    <button id="addInstructorButton" class="btn btn-primary">Add Instructor</button>
  </div>
  <div class="instructors"></div>
  <br>
</div>

<div id="CoursesTab" class="tabcontent">
  <dialog id="addCourseDialogBox">
    <p>
      Input the data for the new course:
    </p>
    <form method="dialog" @submit="onAddCourse()">
      <div class="form-group">
        <label for="add_course_reference_number">Course Reference Number</label>
        <input type="number" class="form-control" name="add_course_reference_number" v-model="add_course_reference_number" min="100" max="500" required/>
      </div>
      <div class="form-group">
        <label for="add_department_code">Department Code</label>
        <input type="text" class="form-control" name="add_department_code" v-model="add_department_code" required/>
      </div>
      <div class="form-group">
        <label for="add_course_number">Course Number</label>
        <input type="number" class="form-control" name="add_course_number" v-model="add_course_number" min="1000" max="9999" required/>
      </div>
      <div>
        <label for="add_course_title">Course Title</label>
        <input type="text" class="form-control" name="add_course_title" v-model="add_course_title" required/>
      </div>
      <div class="form-group">
        <label for="add_course_discipline_area1">Discipline Area 1</label>
        <br>
        <select v-model="add_course_discipline_area1" name="add_course_discipline_area1">
          <option value="None">None</option>
          <option value="Programming-C++">Programming-C++</option>
          <option value="Programming-Python">Programming-Python</option>
          <option value="Software Engineering">Software Engineering</option>
          <option value="Software Development Methodologies">Software Development Methodologies</option>
          <option value="Game Development">Game Development</option>
          <option value="Data Structures and Algorithms">Data Structures and Algorithms</option>
          <option value="Computer Organization">Computer Organization</option>
          <option value="Operating Systems">Operating Systems</option>
          <option value="Programming Languages">Programming Languages</option>
          <option value="Cybersecurity">Cybersecurity</option>
          <option value="Mobile Applications">Mobile Applications</option>
          <option value="Artificial Intelligence">Artificial Intelligence</option>
          <option value="Networks">Networks</option>
          <option value="Theory of Computation">Theory of Computation</option>
          <option value="Parallel and Distributed Systems">Parallel and Distributed Systems</option>
          <option value="Virtual Reality">Virtual Reality</option>
          <option value="Hardware Designs">Hardware Designs</option>
        </select>
      </div>
      <div class="form-group">
        <label for="add_course_discipline_area2">Discipline Area 2</label>
        <br>
        <select v-model="add_course_discipline_area2" name="add_course_discipline_area2">
          <option value="None">None</option>
          <option value="Programming-C++">Programming-C++</option>
          <option value="Programming-Python">Programming-Python</option>
          <option value="Software Engineering">Software Engineering</option>
          <option value="Software Development Methodologies">Software Development Methodologies</option>
          <option value="Game Development">Game Development</option>
          <option value="Data Structures and Algorithms">Data Structures and Algorithms</option>
          <option value="Computer Organization">Computer Organization</option>
          <option value="Operating Systems">Operating Systems</option>
          <option value="Programming Languages">Programming Languages</option>
          <option value="Cybersecurity">Cybersecurity</option>
          <option value="Mobile Applications">Mobile Applications</option>
          <option value="Artificial Intelligence">Artificial Intelligence</option>
          <option value="Networks">Networks</option>
          <option value="Theory of Computation">Theory of Computation</option>
          <option value="Parallel and Distributed Systems">Parallel and Distributed Systems</option>
          <option value="Virtual Reality">Virtual Reality</option>
          <option value="Hardware Designs">Hardware Designs</option>
        </select>
      </div>
      <div class="form-group">
        <label for="add_course_discipline_area3">Discipline Area 3</label>
        <br>
        <select v-model="add_course_discipline_area3" name="add_course_discipline_area3">
          <option value="None">None</option>
          <option value="Programming-C++">Programming-C++</option>
          <option value="Programming-Python">Programming-Python</option>
          <option value="Software Engineering">Software Engineering</option>
          <option value="Software Development Methodologies">Software Development Methodologies</option>
          <option value="Game Development">Game Development</option>
          <option value="Data Structures and Algorithms">Data Structures and Algorithms</option>
          <option value="Computer Organization">Computer Organization</option>
          <option value="Operating Systems">Operating Systems</option>
          <option value="Programming Languages">Programming Languages</option>
          <option value="Cybersecurity">Cybersecurity</option>
          <option value="Mobile Applications">Mobile Applications</option>
          <option value="Artificial Intelligence">Artificial Intelligence</option>
          <option value="Networks">Networks</option>
          <option value="Theory of Computation">Theory of Computation</option>
          <option value="Parallel and Distributed Systems">Parallel and Distributed Systems</option>
          <option value="Virtual Reality">Virtual Reality</option>
          <option value="Hardware Designs">Hardware Designs</option>
        </select>
      </div>
      <div class="form-group">
        <label for="add_course_discipline_area4">Discipline Area 4</label>
        <br>
        <select v-model="add_course_discipline_area4" name="add_course_discipline_area4">
          <option value="None">None</option>
          <option value="Programming-C++">Programming-C++</option>
          <option value="Programming-Python">Programming-Python</option>
          <option value="Software Engineering">Software Engineering</option>
          <option value="Software Development Methodologies">Software Development Methodologies</option>
          <option value="Game Development">Game Development</option>
          <option value="Data Structures and Algorithms">Data Structures and Algorithms</option>
          <option value="Computer Organization">Computer Organization</option>
          <option value="Operating Systems">Operating Systems</option>
          <option value="Programming Languages">Programming Languages</option>
          <option value="Cybersecurity">Cybersecurity</option>
          <option value="Mobile Applications">Mobile Applications</option>
          <option value="Artificial Intelligence">Artificial Intelligence</option>
          <option value="Networks">Networks</option>
          <option value="Theory of Computation">Theory of Computation</option>
          <option value="Parallel and Distributed Systems">Parallel and Distributed Systems</option>
          <option value="Virtual Reality">Virtual Reality</option>
          <option value="Hardware Designs">Hardware Designs</option>
        </select>
      </div>
      <button type="submit" class="btn btn-primary" style="margin: 10px;" value="submit">Submit</button>
      <button type="button" class="btn btn-primary" style="background-color: red; border-color: red" onclick="let dialogBox = document.getElementById('addCourseDialogBox'); dialogBox.close()">Cancel</button>
    </form>
  </dialog>

  <dialog id="modifyCourseDialogBox">
    <p>
      Input the new data for the course:
    </p>
    <form method="dialog" @submit="onModifyCourse()">
      <div class="form-group">
        <label for="modify_course_reference_number">Course Reference Number</label>
        <input type="number" class="form-control" name="modify_course_reference_number" id="modify_course_reference_number" min="100" max="500" required/>
      </div>
      <div class="form-group">
        <label for="modify_department_code">Department Code</label>
        <input type="text" class="form-control" name="modify_department_code" id="modify_department_code" required/>
      </div>
      <div class="form-group">
        <label for="modify_course_number">Course Number</label>
        <input type="number" class="form-control" name="modify_course_number" id="modify_course_number" min="1000" max="9999" required/>
      </div>
      <div>
        <label for="modify_course_title">Course Title</label>
        <input type="text" class="form-control" name="modify_course_title" id="modify_course_title" required/>
      </div>
      <div class="form-group">
        <label for="modify_course_discipline_area1">Discipline Area 1</label>
        <br>
        <select id="modify_course_discipline_area1" name="modify_course_discipline_area1">
          <option value="None">None</option>
          <option value="Programming-C++">Programming-C++</option>
          <option value="Programming-Python">Programming-Python</option>
          <option value="Software Engineering">Software Engineering</option>
          <option value="Software Development Methodologies">Software Development Methodologies</option>
          <option value="Game Development">Game Development</option>
          <option value="Data Structures and Algorithms">Data Structures and Algorithms</option>
          <option value="Computer Organization">Computer Organization</option>
          <option value="Operating Systems">Operating Systems</option>
          <option value="Programming Languages">Programming Languages</option>
          <option value="Cybersecurity">Cybersecurity</option>
          <option value="Mobile Applications">Mobile Applications</option>
          <option value="Artificial Intelligence">Artificial Intelligence</option>
          <option value="Networks">Networks</option>
          <option value="Theory of Computation">Theory of Computation</option>
          <option value="Parallel and Distributed Systems">Parallel and Distributed Systems</option>
          <option value="Virtual Reality">Virtual Reality</option>
          <option value="Hardware Designs">Hardware Designs</option>
        </select>
      </div>
      <div class="form-group">
        <label for="modify_course_discipline_area2">Discipline Area 2</label>
        <br>
        <select id="modify_course_discipline_area2" name="modify_course_discipline_area2">
          <option value="None">None</option>
          <option value="Programming-C++">Programming-C++</option>
          <option value="Programming-Python">Programming-Python</option>
          <option value="Software Engineering">Software Engineering</option>
          <option value="Software Development Methodologies">Software Development Methodologies</option>
          <option value="Game Development">Game Development</option>
          <option value="Data Structures and Algorithms">Data Structures and Algorithms</option>
          <option value="Computer Organization">Computer Organization</option>
          <option value="Operating Systems">Operating Systems</option>
          <option value="Programming Languages">Programming Languages</option>
          <option value="Cybersecurity">Cybersecurity</option>
          <option value="Mobile Applications">Mobile Applications</option>
          <option value="Artificial Intelligence">Artificial Intelligence</option>
          <option value="Networks">Networks</option>
          <option value="Theory of Computation">Theory of Computation</option>
          <option value="Parallel and Distributed Systems">Parallel and Distributed Systems</option>
          <option value="Virtual Reality">Virtual Reality</option>
          <option value="Hardware Designs">Hardware Designs</option>
        </select>
      </div>
      <div class="form-group">
        <label for="modify_course_discipline_area3">Discipline Area 3</label>
        <br>
        <select id="modify_course_discipline_area3" name="modify_course_discipline_area3">
          <option value="None">None</option>
          <option value="Programming-C++">Programming-C++</option>
          <option value="Programming-Python">Programming-Python</option>
          <option value="Software Engineering">Software Engineering</option>
          <option value="Software Development Methodologies">Software Development Methodologies</option>
          <option value="Game Development">Game Development</option>
          <option value="Data Structures and Algorithms">Data Structures and Algorithms</option>
          <option value="Computer Organization">Computer Organization</option>
          <option value="Operating Systems">Operating Systems</option>
          <option value="Programming Languages">Programming Languages</option>
          <option value="Cybersecurity">Cybersecurity</option>
          <option value="Mobile Applications">Mobile Applications</option>
          <option value="Artificial Intelligence">Artificial Intelligence</option>
          <option value="Networks">Networks</option>
          <option value="Theory of Computation">Theory of Computation</option>
          <option value="Parallel and Distributed Systems">Parallel and Distributed Systems</option>
          <option value="Virtual Reality">Virtual Reality</option>
          <option value="Hardware Designs">Hardware Designs</option>
        </select>
      </div>
      <div class="form-group">
        <label for="modify_course_discipline_area4">Discipline Area 4</label>
        <br>
        <select id="modify_course_discipline_area4" name="modify_course_discipline_area4">
          <option value="None">None</option>
          <option value="Programming-C++">Programming-C++</option>
          <option value="Programming-Python">Programming-Python</option>
          <option value="Software Engineering">Software Engineering</option>
          <option value="Software Development Methodologies">Software Development Methodologies</option>
          <option value="Game Development">Game Development</option>
          <option value="Data Structures and Algorithms">Data Structures and Algorithms</option>
          <option value="Computer Organization">Computer Organization</option>
          <option value="Operating Systems">Operating Systems</option>
          <option value="Programming Languages">Programming Languages</option>
          <option value="Cybersecurity">Cybersecurity</option>
          <option value="Mobile Applications">Mobile Applications</option>
          <option value="Artificial Intelligence">Artificial Intelligence</option>
          <option value="Networks">Networks</option>
          <option value="Theory of Computation">Theory of Computation</option>
          <option value="Parallel and Distributed Systems">Parallel and Distributed Systems</option>
          <option value="Virtual Reality">Virtual Reality</option>
          <option value="Hardware Designs">Hardware Designs</option>
        </select>
      </div>
      <button type="submit" class="btn btn-primary" style="margin: 10px;" value="submit">Submit</button>
      <button type="button" class="btn btn-primary" style="background-color: red; border-color: red" onclick="let dialogBox = document.getElementById('modifyCourseDialogBox'); dialogBox.close()">Cancel</button>
    </form>
  </dialog>

  <div style="padding-bottom: 25px;">
    <button id="addCourseButton" class="btn btn-primary">Add Course</button>
  </div>
  <div class="courses"></div>
</div>

<div id="SectionsTab" class="tabcontent">

  <dialog id="addSectionDialogBox">
    <p>
      Input the data for the new section:
    </p>
    <form method="dialog" @submit="onAddSection()">
      <div class="form-group">
        <label for="add_section_CRN">Course Reference Number</label>
        <input type="number" class="form-control" name="add_section_CRN" v-model="add_section_CRN" min="100" max="500" required/>
      </div>
      <div class="form-group">
        <label for="add_section_number">Section Number</label>
        <input type="number" class="form-control" name="add_section_number" v-model="add_section_number" min="1" max="10" required/>
      </div>
      <div class="form-group">
          <label for="add_section_period_1_days">Period 1 Days</label>
          <br>
          <select v-model="add_section_period_1_days" name="add_section_period_1_days" style="width: 100%;">
            <option value="None">None</option>
            <option value="Mon">Mon</option>
            <option value="Mon/Tues">Mon/Tues</option>
            <option value="Mon/Wed">Mon/Wed</option>
            <option value="Mon/Thurs">Mon/Thurs</option>
            <option value="Mon/Fri">Mon/Fri</option>
            <option value="Tues">Tues</option>
            <option value="Tues/Wed">Tues/Wed</option>
            <option value="Tues/Thurs">Tues/Thurs</option>
            <option value="Tues/Fri">Tues/Fri</option>
            <option value="Wed">Wed</option>
            <option value="Wed/Thurs">Wed/Thurs</option>
            <option value="Wed/Fri">Wed/Fri</option>
            <option value="Thurs">Thurs</option>
            <option value="Thurs/Fri">Thurs/Fri</option>
            <option value="Fri">Fri</option>
          </select>
      </div>
      <div class="form-group">
        <label for="add_section_period_1_start_time">Period 1 Start Time</label>
        <input type="time" class="form-control" name="add_section_period_1_start_time" v-model="add_section_period_1_start_time"/>
      </div>
      <div class="form-group">
        <label for="add_section_period_1_end_time">Period 1 End Time</label>
        <input type="time" class="form-control" name="add_section_period_1_end_time" v-model="add_section_period_1_end_time"/>
      </div>

      <div class="form-group">
          <label for="add_section_period_2_days">Period 2 Days</label>
          <br>
          <select v-model="add_section_period_2_days" name="add_section_period_2_days" style="width: 100%;">
            <option value="None">None</option>
            <option value="Mon">Mon</option>
            <option value="Mon/Tues">Mon/Tues</option>
            <option value="Mon/Wed">Mon/Wed</option>
            <option value="Mon/Thurs">Mon/Thurs</option>
            <option value="Mon/Fri">Mon/Fri</option>
            <option value="Tues">Tues</option>
            <option value="Tues/Wed">Tues/Wed</option>
            <option value="Tues/Thurs">Tues/Thurs</option>
            <option value="Tues/Fri">Tues/Fri</option>
            <option value="Wed">Wed</option>
            <option value="Wed/Thurs">Wed/Thurs</option>
            <option value="Wed/Fri">Wed/Fri</option>
            <option value="Thurs">Thurs</option>
            <option value="Thurs/Fri">Thurs/Fri</option>
            <option value="Fri">Fri</option>
          </select>
      </div>
      <div class="form-group">
        <label for="add_section_period_2_start_time">Period 2 Start Time</label>
        <input type="time" class="form-control" name="add_section_period_2_start_time" v-model="add_section_period_2_start_time"/>
      </div>
      <div class="form-group">
        <label for="add_section_period_2_end_time">Period 2 End Time</label>
        <input type="time" class="form-control" name="add_section_period_2_end_time" v-model="add_section_period_2_end_time"/>
      </div>

      <div class="form-group">
          <label for="add_section_period_3_days">Period 3 Days</label>
          <br>
          <select v-model="add_section_period_3_days" name="add_section_period_3_days" style="width: 100%;">
            <option value="None">None</option>
            <option value="Mon">Mon</option>
            <option value="Mon/Tues">Mon/Tues</option>
            <option value="Mon/Wed">Mon/Wed</option>
            <option value="Mon/Thurs">Mon/Thurs</option>
            <option value="Mon/Fri">Mon/Fri</option>
            <option value="Tues">Tues</option>
            <option value="Tues/Wed">Tues/Wed</option>
            <option value="Tues/Thurs">Tues/Thurs</option>
            <option value="Tues/Fri">Tues/Fri</option>
            <option value="Wed">Wed</option>
            <option value="Wed/Thurs">Wed/Thurs</option>
            <option value="Wed/Fri">Wed/Fri</option>
            <option value="Thurs">Thurs</option>
            <option value="Thurs/Fri">Thurs/Fri</option>
            <option value="Fri">Fri</option>
          </select>
      </div>
      <div class="form-group">
        <label for="add_section_period_3_start_time">Period 3 Start Time</label>
        <input type="time" class="form-control" name="add_section_period_3_start_time" v-model="add_section_period_3_start_time"/>
      </div>
      <div class="form-group">
        <label for="add_section_period_3_end_time">Period 3 End Time</label>
        <input type="time" class="form-control" name="add_section_period_3_end_time" v-model="add_section_period_3_end_time"/>
      </div>
      
      <button type="submit" class="btn btn-primary" style="margin: 10px;" value="submit">Submit</button>
      <button type="button" class="btn btn-primary" style="background-color: red; border-color: red" onclick="let dialogBox = document.getElementById('addSectionDialogBox'); dialogBox.close()">Cancel</button>
    </form>
  </dialog>

  <dialog id="modifySectionDialogBox">
    <p>
      Input the new data for the section:
    </p>
    <form method="dialog" @submit="onModifySection()">
      <div class="form-group">
        <label for="modify_section_CRN">Course Reference Number</label>
        <input type="number" class="form-control" name="modify_section_CRN" id="modify_section_CRN" min="100" max="500" required/>
      </div>
      <div class="form-group">
        <label for="modify_section_number">Section Number</label>
        <input type="number" class="form-control" name="modify_section_number" id="modify_section_number" min="1" max="10" required/>
      </div>
      <div class="form-group">
          <label for="modify_section_period_1_days">Period 1 Days</label>
          <br>
          <select id="modify_section_period_1_days" name="modify_section_period_1_days" style="width: 100%;">
            <option value="None">None</option>
            <option value="Mon">Mon</option>
            <option value="Mon/Tues">Mon/Tues</option>
            <option value="Mon/Wed">Mon/Wed</option>
            <option value="Mon/Thurs">Mon/Thurs</option>
            <option value="Mon/Fri">Mon/Fri</option>
            <option value="Tues">Tues</option>
            <option value="Tues/Wed">Tues/Wed</option>
            <option value="Tues/Thurs">Tues/Thurs</option>
            <option value="Tues/Fri">Tues/Fri</option>
            <option value="Wed">Wed</option>
            <option value="Wed/Thurs">Wed/Thurs</option>
            <option value="Wed/Fri">Wed/Fri</option>
            <option value="Thurs">Thurs</option>
            <option value="Thurs/Fri">Thurs/Fri</option>
            <option value="Fri">Fri</option>
          </select>
      </div>
      <div class="form-group">
        <label for="modify_section_period_1_start_time">Period 1 Start Time</label>
        <input type="time" class="form-control" name="modify_section_period_1_start_time" id="modify_section_period_1_start_time"/>
      </div>
      <div class="form-group">
        <label for="modify_section_period_1_end_time">Period 1 End Time</label>
        <input type="time" class="form-control" name="modify_section_period_1_end_time" id="modify_section_period_1_end_time"/>
      </div>

      <div class="form-group">
          <label for="modify_section_period_2_days">Period 2 Days</label>
          <br>
          <select id="modify_section_period_2_days" name="modify_section_period_2_days" style="width: 100%;">
            <option value="None">None</option>
            <option value="Mon">Mon</option>
            <option value="Mon/Tues">Mon/Tues</option>
            <option value="Mon/Wed">Mon/Wed</option>
            <option value="Mon/Thurs">Mon/Thurs</option>
            <option value="Mon/Fri">Mon/Fri</option>
            <option value="Tues">Tues</option>
            <option value="Tues/Wed">Tues/Wed</option>
            <option value="Tues/Thurs">Tues/Thurs</option>
            <option value="Tues/Fri">Tues/Fri</option>
            <option value="Wed">Wed</option>
            <option value="Wed/Thurs">Wed/Thurs</option>
            <option value="Wed/Fri">Wed/Fri</option>
            <option value="Thurs">Thurs</option>
            <option value="Thurs/Fri">Thurs/Fri</option>
            <option value="Fri">Fri</option>
          </select>
      </div>
      <div class="form-group">
        <label for="modify_section_period_2_start_time">Period 2 Start Time</label>
        <input type="time" class="form-control" name="modify_section_period_2_start_time" id="modify_section_period_2_start_time"/>
      </div>
      <div class="form-group">
        <label for="modify_section_period_2_end_time">Period 2 End Time</label>
        <input type="time" class="form-control" name="modify_section_period_2_end_time" id="modify_section_period_2_end_time"/>
      </div>

      <div class="form-group">
          <label for="modify_section_period_3_days">Period 3 Days</label>
          <br>
          <select id="modify_section_period_3_days" name="modify_section_period_3_days" style="width: 100%;">
            <option value="None">None</option>
            <option value="Mon">Mon</option>
            <option value="Mon/Tues">Mon/Tues</option>
            <option value="Mon/Wed">Mon/Wed</option>
            <option value="Mon/Thurs">Mon/Thurs</option>
            <option value="Mon/Fri">Mon/Fri</option>
            <option value="Tues">Tues</option>
            <option value="Tues/Wed">Tues/Wed</option>
            <option value="Tues/Thurs">Tues/Thurs</option>
            <option value="Tues/Fri">Tues/Fri</option>
            <option value="Wed">Wed</option>
            <option value="Wed/Thurs">Wed/Thurs</option>
            <option value="Wed/Fri">Wed/Fri</option>
            <option value="Thurs">Thurs</option>
            <option value="Thurs/Fri">Thurs/Fri</option>
            <option value="Fri">Fri</option>
          </select>
      </div>
      <div class="form-group">
        <label for="modify_section_period_3_start_time">Period 3 Start Time</label>
        <input type="time" class="form-control" name="modify_section_period_3_start_time" id="modify_section_period_3_start_time"/>
      </div>
      <div class="form-group">
        <label for="modify_section_period_3_end_time">Period 3 End Time</label>
        <input type="time" class="form-control" name="modify_section_period_3_end_time" id="modify_section_period_3_end_time"/>
      </div>
      
      <button type="submit" class="btn btn-primary" style="margin: 10px;" value="submit">Submit</button>
      <button type="button" class="btn btn-primary" style="background-color: red; border-color: red" onclick="let dialogBox = document.getElementById('modifySectionDialogBox'); dialogBox.close()">Cancel</button>
    </form>
  </dialog>

  <div style="padding-bottom: 25px;">
    <button id="addSectionButton" class="btn btn-primary">Add Section</button>
  </div>
  <div class="sections"></div>

</div>
</center>
</body>
</template>

<script>
  import axios from "axios";

  //Global Variables
  var currentInstructorID
  var currentCourseCRN
  var currentSectionID

export default ({
    name: "Setup-Page",
    data()
    {
      return {
        add_last_name: "",
        add_max_course_load: "",
        add_instructor_discipline_area1: "",
        add_instructor_discipline_area2: "",
        add_instructor_discipline_area3: "",
        add_instructor_discipline_area4: "",

        add_course_reference_number: "",
        add_department_code: "",
        add_course_number: "",
        add_course_title: "",
        add_course_discipline_area1: "",
        add_course_discipline_area2: "",
        add_course_discipline_area3: "",
        add_course_discipline_area4: "",

        add_section_CRN: "",
        add_section_number: "",
        add_section_period_1_days: "",
        add_section_period_1_start_time: "",
        add_section_period_1_end_time: "",
        add_section_period_2_days: "",
        add_section_period_2_start_time: "",
        add_section_period_2_end_time: "",
        add_section_period_3_days: "",
        add_section_period_3_start_time: "",
        add_section_period_3_end_time: "",

      };
    },

    //Methods to call at page creation
    mounted: function() {
      
      //Add instructor
      const addInstructorButton = document.getElementById('addInstructorButton')
      const addInstructorDialogBox = document.getElementById('addInstructorDialogBox')

      addInstructorButton.onclick = function()
      {
        addInstructorDialogBox.showModal()
      }

      //Add Course
      const addCourseButton = document.getElementById('addCourseButton')
      const addCourseDialogBox = document.getElementById('addCourseDialogBox')

      addCourseButton.onclick = function()
      {
        addCourseDialogBox.showModal()
      }

      //Add Section
      const addSectionButton = document.getElementById('addSectionButton')
      const addSectionDialogBox = document.getElementById('addSectionDialogBox')

      addSectionButton.onclick = function()
      {
        addSectionDialogBox.showModal()
      }

      //List data and set default tab
      this.$nextTick(function ()
      {
        this.getInstructors()
        this.getCourses()
        this.getSections()
        this.openTab('openInstructors', 'InstructorsTab')
      })
    },
    methods:
    {
      //Tab Management
      openTab(buttonName, tabName)
      {
        var i, tabcontent, tablinks
        tabcontent = document.getElementsByClassName("tabcontent")
        for (i = 0; i < tabcontent.length; i++)
        {
          tabcontent[i].style.display = "none"
        }
        tablinks = document.getElementsByClassName("tablinks")
        for (i = 0; i < tablinks.length; i++)
        {
          tablinks[i].className = tablinks[i].className.replace(" active", "")
        }
        document.getElementById(tabName).style.display = "block"
        document.getElementById(buttonName).className += " active"
      },

      //Functions to convert data to database format
      convertDisciplineToId(disciplineArea)
      {
        switch(disciplineArea)
        {
          case "None":
            return undefined;
          case "Programming-C++":
            return 1;
          case "Programming-Python":
            return 2;
          case "Software Engineering":
            return 3;
          case "Software Development Methodologies":
            return 4;
          case "Game Development":
            return 5;
          case "Data Structures and Algorithms":
            return 6;
          case "Computer Organization":
            return 7;
          case "Operating Systems":
            return 8;
          case "Programming Languages":
            return 9;
          case "Cybersecurity":
            return 10;
          case "Mobile Applications":
            return 11;
          case "Artificial Intelligence":
            return 12;
          case "Networks":
            return 13;
          case "Theory of Computation":
            return 14;
          case "Parallel and Distributed Systems":
            return 15;
          case "Virtual Reality":
            return 16;
          case "Hardware Designs":
            return 17;
          default:
            return undefined;
        }
      },

      convertToDaysString(daysInteger)
      {
          switch(daysInteger)
          {
            case 16:
                return "Mon";
            case 24:
                return "Mon/Tues";
            case 20:
                return "Mon/Wed";
            case 18:
                return "Mon/Thurs";
            case 17:
                return "Mon/Fri";
            case 8:
                return "Tues";
            case 12:
                return "Tues/Wed";
            case 10:
                return "Tues/Thurs";
            case 9:
                return "Tues/Fri";
            case 4:
                return "Wed";
            case 6:
                return "Wed/Thurs";
            case 5:
                return "Wed/Fri";
            case 2:
                return "Thurs";
            case 3:
                return "Thurs/Fri";
            case 1:
                return "Fri";
            default:
              return "None";
          }
      },

      convertToDaysInteger(daysString)
      {
        switch(daysString)
        {
          case "None":
            return undefined;
          case "Mon":
            return 16;
          case "Mon/Tues":
            return 24;
          case "Mon/Wed":
            return 20;
          case "Mon/Thurs":
            return 18;
          case "Mon/Fri":
            return 17;
          case "Tues":
            return 8;
          case "Tues/Wed":
            return 12;
          case "Tues/Thurs":
            return 10;
          case "Wed":
            return 4;
          case "Wed/Thurs":
            return 6;
          case "Wed/Fri":
            return 5;
          case "Thurs":
            return 2;
          case "Thurs/Fri":
            return 3;
          case "Fri":
            return 1;
          default:
            return undefined;
        }
      },

      convertToPrintedTime(time)
      {
          let tempHour;
          let tempMinute;
          let pmOrAm
          if (time == undefined)
          {
              return ("???")
          }
          if (time.toString().length == 1)
          {
              tempHour = 0;
              tempMinute = "0" + time.toString();
          }
          else if (time.toString().length == 2)
          {
              tempHour = 0;
              tempMinute = time.toString();
          }
          else if (time.toString().length == 3)
          {
              tempHour = time.toString().substr(0, 1);
              tempMinute = time.toString().substr(1, 2);
          }
          else if (time.toString().length == 4)
          {
              tempHour = time.toString().substr(0, 2);
              tempMinute= time.toString().substr(2, 2);
                  
          }

          if (tempHour > 12)
          {
              pmOrAm = "PM";
              tempHour -= 12;
          }
          else if (tempHour == 12)
          {
              pmOrAm = "PM"
          }
          else if(tempHour == 0)
          {
              pmOrAm = "AM"
              tempHour += 12
          }
          else
          {
            pmOrAm = "AM"
          }

          return (tempHour +":" + tempMinute + pmOrAm);
      },

      convertTo24HourTime(time)
      {
          let tempHour;
          let tempMinute;
          if (time == undefined)
          {
              return undefined;
          }
          if (time.toString().length == 1)
          {
              tempHour = "00";
              tempMinute = "0" + time.toString();
          }
          else if (time.toString().length == 2)
          {
              tempHour = "00";
              tempMinute = time.toString();
          }
          else if (time.toString().length == 3)
          {
              tempHour = "0" + time.toString().substr(0, 1);
              tempMinute = time.toString().substr(1, 2);
          }
          else if (time.toString().length == 4)
          {
              tempHour = time.toString().substr(0, 2);
              tempMinute= time.toString().substr(2, 2);
                  
          }

          return (tempHour +":" + tempMinute);
      },

      convertToDatabaseTime(time)
      {
        if (time == undefined)
        {
          return undefined;
        }
        let tempHour = time.toString().substr(0, 2);
        let tempMinute = time.toString().substr(3, 2);
        return (parseInt(tempHour.toString() + tempMinute.toString()));
      },

      //Instructor Functions
      onAddInstructor()
      {
      var url = ''
        if (process.env.NODE_ENV === 'development') {
        url = 'http://localhost:3333'
        } 
        else {
        url = 'https://test-adoni.herokuapp.com'
        }

        console.log(this.add_last_name, this.add_max_course_load, this.add_instructor_discipline_area1, this.add_instructor_discipline_area2, this.add_instructor_discipline_area3, this.add_instructor_discipline_area4)
        let disciplineID1 = this.convertDisciplineToId(this.add_instructor_discipline_area1)
        let disciplineID2 = this.convertDisciplineToId(this.add_instructor_discipline_area2)
        let disciplineID3 = this.convertDisciplineToId(this.add_instructor_discipline_area3)
        let disciplineID4 = this.convertDisciplineToId(this.add_instructor_discipline_area4)

        axios.post(`${url}/api/v0/setup/addInstructor`, 
        {
          Last_Name: this.add_last_name, 
          Max_Course_Load: this.add_max_course_load, 
          Discipline_ID_1: disciplineID1, 
          Discipline_ID_2: disciplineID2, 
          Discipline_ID_3: disciplineID3, 
          Discipline_ID_4: disciplineID4
        }, { headers: { Authorization: `Bearer ${localStorage.getItem('token')}`}})
        .then((response) => 
        {
          console.log(response)
          this.getInstructors()
        })
       
      },
      onModifyInstructor()
      {
        var url = ''
        if (process.env.NODE_ENV === 'development') {
          url = 'http://localhost:3333'
        } 
        else {
          url = 'https://test-adoni.herokuapp.com'
        }

        const lastName = document.getElementById("modify_last_name").value
        const maxCourseLoad = document.getElementById("modify_max_course_load").value
        const disciplineArea1 = document.getElementById("modify_instructor_discipline_area1").value
        const disciplineArea2 = document.getElementById("modify_instructor_discipline_area2").value
        const disciplineArea3 = document.getElementById("modify_instructor_discipline_area3").value
        const disciplineArea4 = document.getElementById("modify_instructor_discipline_area4").value
        console.log(lastName, maxCourseLoad, disciplineArea1, disciplineArea2, disciplineArea3, disciplineArea4)

        let disciplineID1 = this.convertDisciplineToId(disciplineArea1)
        let disciplineID2 = this.convertDisciplineToId(disciplineArea2)
        let disciplineID3 = this.convertDisciplineToId(disciplineArea3)
        let disciplineID4 = this.convertDisciplineToId(disciplineArea4)
        
        axios.post(`${url}/api/v0/setup/modify-instructor/` + currentInstructorID,
        {
          Last_Name: lastName, 
          Max_Course_Load: maxCourseLoad, 
          Discipline_ID_1: disciplineID1, 
          Discipline_ID_2: disciplineID2, 
          Discipline_ID_3: disciplineID3, 
          Discipline_ID_4: disciplineID4
        }, { headers: { Authorization: `Bearer ${localStorage.getItem('token')}`}})
        .then((response) =>
        {
          console.log(response)
          this.getInstructors()
        })
      },

      //Instructor Importing
      createInstructorTable() {
        const instructorDiv = document.querySelector('div.instructors')
        let tableHeaders = ["ID", "Last Name", "Max Course Load", "Discipline Area 1", "Discipline Area 2", "Discipline Area 3", "Discipline Area 4"]
        while (instructorDiv.firstChild)
        {
          instructorDiv.removeChild(instructorDiv.firstChild);
        }

          let instructorTable = document.createElement('table')
          instructorTable.className = 'instructorTable'

          let instructorTableHead = document.createElement('thead')
          instructorTableHead.className = 'instructorTableHead'

          let instructorTableHeaderRow = document.createElement('tr')
          instructorTableHeaderRow.className = 'instructorTableHeaderRow'

        tableHeaders.forEach(header => {
          let instructorHeader = document.createElement('th')
          instructorHeader.innerText = header
          instructorHeader.style.textAlign = 'center'
          instructorHeader.style.padding = '10px'
          instructorTableHeaderRow.append(instructorHeader)
        })
        
        instructorTableHead.append(instructorTableHeaderRow)
        instructorTable.append(instructorTableHead)

        let instructorTableBody = document.createElement('tbody')
        instructorTableBody.className = 'instructorTable-Body'
        instructorTable.append(instructorTableBody)

        instructorDiv.append(instructorTable)
      },

      appendInstructors(singleInstructor) {
        var url = ''
        if (process.env.NODE_ENV === 'development') {
          url = 'http://localhost:3333'
        } 
        else {
          url = 'https://test-adoni.herokuapp.com'
        }
        const instructorTable = document.querySelector('.instructorTable')

        let instructorTableByBodyRow = document.createElement('tr')
        instructorTableByBodyRow.className = 'instructorTableByBodyRow'

        let instructorID = document.createElement('td')
        instructorID.innerText = singleInstructor.id;
        instructorID.style.textAlign = 'center'

        let instructorLastName = document.createElement('td')
        instructorLastName.innerText = singleInstructor.Last_Name
        instructorLastName.style.textAlign = 'center'
        instructorLastName.style.width = '10em'

        let instructorMaxLoad = document.createElement('td')
        instructorMaxLoad.innerText = singleInstructor.Max_Course_Load
        instructorMaxLoad.style.textAlign = 'center'

        let instructorDisciplineArea1 = document.createElement('td')
        instructorDisciplineArea1.style.textAlign = 'center'
        instructorDisciplineArea1.style.width = '10em'
        if (singleInstructor.Discipline_Area1 == undefined)
        {
            instructorDisciplineArea1.innerText = ""
        }
        else
        {
        instructorDisciplineArea1.innerText = singleInstructor.Discipline_Area1
        }

        let instructorDisciplineArea2 = document.createElement('td')
        instructorDisciplineArea2.style.textAlign = 'center'
        instructorDisciplineArea2.style.width = '10em'
        if (singleInstructor.Discipline_Area2 == undefined)
        {
            instructorDisciplineArea2.innerText = ""
        }
        else
        {
          instructorDisciplineArea2.innerText = singleInstructor.Discipline_Area2
        }

        let instructorDisciplineArea3 = document.createElement('td')
        instructorDisciplineArea3.style.textAlign = 'center'
        instructorDisciplineArea3.style.width = '10em'
        if (singleInstructor.Discipline_Area3 == undefined)
        {
            instructorDisciplineArea3.innerText = ""
        }
        else
        {
          instructorDisciplineArea3.innerText = singleInstructor.Discipline_Area3
        }

        let instructorDisciplineArea4 = document.createElement('td')
        instructorDisciplineArea4.style.textAlign = 'center'
        instructorDisciplineArea4.style.width = '10em'
        if (singleInstructor.Discipline_Area4 == undefined)
        {
            instructorDisciplineArea4.innerText = ""
        }
        else
        {
          instructorDisciplineArea4.innerText = singleInstructor.Discipline_Area4
        }

        //Modify Instructor Button
        let modifyInstructorButton = document.createElement("button")
        modifyInstructorButton.innerText = "Modify Instructor " + singleInstructor.id
        modifyInstructorButton.style.margin = "10px"
        modifyInstructorButton.className = "btn btn-primary"
        modifyInstructorButton.onclick = function () 
        {
          const modifyInstructorDialogBox = document.getElementById('modifyInstructorDialogBox')

          const lastNameField = document.getElementById("modify_last_name")
          lastNameField.value = singleInstructor.Last_Name

          const maxCourseLoadField = document.getElementById("modify_max_course_load")
          maxCourseLoadField.value = singleInstructor.Max_Course_Load

          const disciplineAreaField1 = document.getElementById("modify_instructor_discipline_area1")
          disciplineAreaField1.value = singleInstructor.Discipline_Area1

          const disciplineAreaField2 = document.getElementById("modify_instructor_discipline_area2")
          disciplineAreaField2.value = singleInstructor.Discipline_Area2

          const disciplineAreaField3 = document.getElementById("modify_instructor_discipline_area3")
          disciplineAreaField3.value = singleInstructor.Discipline_Area3

          const disciplineAreaField4 = document.getElementById("modify_instructor_discipline_area4")
          disciplineAreaField4.value = singleInstructor.Discipline_Area4

          currentInstructorID = singleInstructor.id

          modifyInstructorDialogBox.showModal()
        }
        
        //Delete Instructor Button
        let setup = this
        let deleteInstructorButton = document.createElement("button")
        deleteInstructorButton.innerText = "Delete Instructor " + singleInstructor.id
        deleteInstructorButton.className = "btn btn-primary"
        deleteInstructorButton.style.backgroundColor = "red"
        deleteInstructorButton.style.border = "red"
        deleteInstructorButton.onclick = function () {
          axios.delete(`${url}/api/v0/setup/delete-instructor/` + singleInstructor.id, { headers: { Authorization: `Bearer ${localStorage.getItem('token')}`}})
          .then((response) =>
          {
            console.log(response)
            setup.getInstructors()
          })
        }

        instructorTableByBodyRow.append(instructorID, instructorLastName, instructorMaxLoad, instructorDisciplineArea1, instructorDisciplineArea2, instructorDisciplineArea3, instructorDisciplineArea4, modifyInstructorButton, deleteInstructorButton)
        instructorTable.append(instructorTableByBodyRow)
      },

      getInstructors() {
        var url = ''
        if (process.env.NODE_ENV === 'development') {
          url = 'http://localhost:3333'
        } 
        else {
          url = 'https://test-adoni.herokuapp.com'
        }
        fetch(`${url}/api/v0/setup/instructors`, { headers: { Authorization: `Bearer ${localStorage.getItem('token')}`}})
        .then(res => res.json())
        .then(instructors => {
          this.createInstructorTable()

          for (const instructor of instructors) {
            let instructorIndex = instructors.indexOf(instructor) + 1
            console.log(instructor)
            this.appendInstructors(instructor, instructorIndex)
          }
        })
      },
      
      //Course Functions
      onAddCourse()
      {
        var url = ''
        if (process.env.NODE_ENV === 'development') {
          url = 'http://localhost:3333'
        } 
        else {
          url = 'https://test-adoni.herokuapp.com'
        }
        console.log(this.add_course_reference_number, this.add_department_code, this.add_course_number, this.add_course_title, this.add_course_discipline_area1, this.add_course_discipline_area2, this.add_course_discipline_area3, this.add_course_discipline_area4)
        let disciplineID1 = this.convertDisciplineToId(this.add_course_discipline_area1)
        let disciplineID2 = this.convertDisciplineToId(this.add_course_discipline_area2)
        let disciplineID3 = this.convertDisciplineToId(this.add_course_discipline_area3)
        let disciplineID4 = this.convertDisciplineToId(this.add_course_discipline_area4)

        axios.post(`${url}/api/v0/setup/addCourse`, 
        {
          Course_Reference_Number: this.add_course_reference_number, 
          Department_Code: this.add_department_code,
          Course_Number: this.add_course_number,
          Course_Title: this.add_course_title,
          Discipline_ID_1: disciplineID1, 
          Discipline_ID_2: disciplineID2, 
          Discipline_ID_3: disciplineID3, 
          Discipline_ID_4: disciplineID4
        }, { headers: { Authorization: `Bearer ${localStorage.getItem('token')}`}})
        .then((response) => 
        {
          console.log(response)
          this.getCourses()
        })       
      },

      onModifyCourse()
      {
        var url = ''
        if (process.env.NODE_ENV === 'development') {
          url = 'http://localhost:3333'
        } 
        else {
          url = 'https://test-adoni.herokuapp.com'
        }
        const CRN = document.getElementById("modify_course_reference_number").value
        const departmentCode = document.getElementById("modify_department_code").value
        const courseNumber = document.getElementById("modify_course_number").value
        const courseTitle = document.getElementById("modify_course_title").value
        const disciplineArea1 = document.getElementById("modify_course_discipline_area1").value
        const disciplineArea2 = document.getElementById("modify_course_discipline_area2").value
        const disciplineArea3 = document.getElementById("modify_course_discipline_area3").value
        const disciplineArea4 = document.getElementById("modify_course_discipline_area4").value
        console.log(CRN, departmentCode, courseNumber, courseTitle, disciplineArea1, disciplineArea2, disciplineArea3, disciplineArea4)

        let disciplineID1 = this.convertDisciplineToId(disciplineArea1)
        let disciplineID2 = this.convertDisciplineToId(disciplineArea2)
        let disciplineID3 = this.convertDisciplineToId(disciplineArea3)
        let disciplineID4 = this.convertDisciplineToId(disciplineArea4)
        
        axios.post(`${url}/api/v0/setup/modify-course/` + currentCourseCRN,
        {
          Course_Reference_Number: CRN, 
          Department_Code: departmentCode,
          Course_Number: courseNumber,
          Course_Title: courseTitle,
          Discipline_ID_1: disciplineID1, 
          Discipline_ID_2: disciplineID2, 
          Discipline_ID_3: disciplineID3, 
          Discipline_ID_4: disciplineID4
        }, { headers: { Authorization: `Bearer ${localStorage.getItem('token')}`}})
        .then((response) =>
        {
          console.log(response)
          this.getCourses()
        })
      },

      //Course Importing
      createCourseTable() {
        const courseDiv = document.querySelector('div.courses')
        let tableHeaders = ["CRN", "Department Code","Course Number", "Course Title", "Discipline Area 1", "Discipline Area 2", "Discipline Area 3", "Discipline Area 4"]
        while (courseDiv.firstChild)
        {
          courseDiv.removeChild(courseDiv.firstChild);
        }

          let courseTable = document.createElement('table')
          courseTable.className = 'courseTable'

          let courseTableHead = document.createElement('thead')
          courseTableHead.className = 'courseTableHead'

          let courseTableHeaderRow = document.createElement('tr')
          courseTableHeaderRow.className = 'courseTableHeaderRow'

        tableHeaders.forEach(header => {
          let courseHeader = document.createElement('th')
          courseHeader.innerText = header
          courseHeader.style.textAlign = 'center'
          courseHeader.style.padding = '10px'
          courseTableHeaderRow.append(courseHeader)
        })
        
        courseTableHead.append(courseTableHeaderRow)
        courseTable.append(courseTableHead)

        let courseTableBody = document.createElement('tbody')
        courseTableBody.className = 'courseTable-Body'
        courseTable.append(courseTableBody)

        courseDiv.append(courseTable)
      },

      appendCourses(singleCourse) {
        var url = ''
        if (process.env.NODE_ENV === 'development') {
          url = 'http://localhost:3333'
        } 
        else {
          url = 'https://test-adoni.herokuapp.com'
        }
        const courseTable = document.querySelector('.courseTable')

        let courseTableByBodyRow = document.createElement('tr')
        courseTableByBodyRow.className = 'courseTableByBodyRow'

        let courseCRN = document.createElement('td')
        courseCRN.innerText = singleCourse.Course_Reference_Number
        courseCRN.style.textAlign = 'center'

        let courseDepartmentCode = document.createElement('td')
        courseDepartmentCode.innerText = singleCourse.Department_Code
        courseDepartmentCode.style.textAlign = 'center'
        courseDepartmentCode.style.width = '10em'

        let courseNumber = document.createElement('td')
        courseNumber.innerText = singleCourse.Course_Number
        courseNumber.style.textAlign = 'center'

        let courseTitle = document.createElement('td')
        courseTitle.innerText = singleCourse.Course_Title
        courseTitle.style.textAlign = 'center'
        courseTitle.style.width = '10em'

        let courseDisciplineArea1 = document.createElement('td')
        courseDisciplineArea1.style.textAlign = 'center'
        courseDisciplineArea1.style.width = '10em'
        if (singleCourse.Discipline_Area1 == undefined)
        {
            courseDisciplineArea1.innerText = ""
        }
        else
        {
        courseDisciplineArea1.innerText = singleCourse.Discipline_Area1
        }

        let courseDisciplineArea2 = document.createElement('td')
        courseDisciplineArea2.style.textAlign = 'center'
        courseDisciplineArea2.style.width = '10em'
        if (singleCourse.Discipline_Area2 == undefined)
        {
            courseDisciplineArea2.innerText = ""
        }
        else
        {
          courseDisciplineArea2.innerText = singleCourse.Discipline_Area2
        }

        let courseDisciplineArea3 = document.createElement('td')
        courseDisciplineArea3.style.textAlign = 'center'
        courseDisciplineArea3.style.width = '10em'
        if (singleCourse.Discipline_Area3 == undefined)
        {
            courseDisciplineArea3.innerText = ""
        }
        else
        {
          courseDisciplineArea3.innerText = singleCourse.Discipline_Area3
        }

        let courseDisciplineArea4 = document.createElement('td')
        courseDisciplineArea4.style.textAlign = 'center'
        courseDisciplineArea4.style.width = '10em'
        if (singleCourse.Discipline_Area4 == undefined)
        {
            courseDisciplineArea4.innerText = ""
        }
        else
        {
          courseDisciplineArea4.innerText = singleCourse.Discipline_Area4
        }

        //Modify Course Button
        let modifyCourseButton = document.createElement("button")
        modifyCourseButton.innerText = "Modify Course " + singleCourse.Course_Reference_Number
        modifyCourseButton.style.margin = "10px"
        modifyCourseButton.className = "btn btn-primary"
        modifyCourseButton.onclick = function () 
        {
          const modifyCourseDialogBox = document.getElementById('modifyCourseDialogBox')

          const CRNField = document.getElementById("modify_course_reference_number")
          CRNField.value = singleCourse.Course_Reference_Number

          const departmentCodeField = document.getElementById("modify_department_code")
          departmentCodeField.value = singleCourse.Department_Code

          const courseNumberField = document.getElementById("modify_course_number")
          courseNumberField.value = singleCourse.Course_Number

          const courseTitleField = document.getElementById("modify_course_title")
          courseTitleField.value = singleCourse.Course_Title

          const disciplineAreaField1 = document.getElementById("modify_course_discipline_area1")
          disciplineAreaField1.value = singleCourse.Discipline_Area1

          const disciplineAreaField2 = document.getElementById("modify_course_discipline_area2")
          disciplineAreaField2.value = singleCourse.Discipline_Area2

          const disciplineAreaField3 = document.getElementById("modify_course_discipline_area3")
          disciplineAreaField3.value = singleCourse.Discipline_Area3

          const disciplineAreaField4 = document.getElementById("modify_course_discipline_area4")
          disciplineAreaField4.value = singleCourse.Discipline_Area4

          currentCourseCRN = singleCourse.Course_Reference_Number
          console.log(currentCourseCRN)

          modifyCourseDialogBox.showModal()
        }

        //Delete Course Button
        let setup = this
        let deleteCourseButton = document.createElement("button")
        deleteCourseButton.innerText = "Delete Course " + singleCourse.Course_Reference_Number
        deleteCourseButton.className = "btn btn-primary"
        deleteCourseButton.style.backgroundColor = "red"
        deleteCourseButton.style.border = "red"
        deleteCourseButton.onclick = function () {
          axios.delete(`${url}/api/v0/setup/delete-course/` + singleCourse.Course_Reference_Number, { headers: { Authorization: `Bearer ${localStorage.getItem('token')}`}})
          .then((response) =>
          {
            console.log(response)
            setup.getCourses()
          })
        }

        courseTableByBodyRow.append(courseCRN, courseDepartmentCode, courseNumber, courseTitle, courseDisciplineArea1, courseDisciplineArea2, courseDisciplineArea3, courseDisciplineArea4, modifyCourseButton, deleteCourseButton)
        courseTable.append(courseTableByBodyRow)
      },

      getCourses() {
        var url = ''
        if (process.env.NODE_ENV === 'development') {
          url = 'http://localhost:3333'
        } 
        else {
          url = 'https://test-adoni.herokuapp.com'
        }
        fetch(`${url}/api/v0/setup/courses`, { headers: { Authorization: `Bearer ${localStorage.getItem('token')}`}})
        .then(res => res.json())
        .then(courses => {
          this.createCourseTable()

          for (const course of courses) {
            let courseIndex = courses.indexOf(course) + 1
            console.log(course)
            this.appendCourses(course, courseIndex)
          }
        })
      },

      //Section Functions
      onAddSection()
      {
        var url = ''
        if (process.env.NODE_ENV === 'development') {
          url = 'http://localhost:3333'
        } 
        else {
          url = 'https://test-adoni.herokuapp.com'
        }
        console.log(
            this.add_section_CRN, 
            this.add_section_number, 
            this.add_section_period_1_days, this.add_section_period_1_start_time, this.add_section_period_1_end_time,
            this.add_section_period_2_days, this.add_section_period_2_start_time, this.add_section_period_2_end_time,
            this.add_section_period_3_days, this.add_section_period_3_start_time, this.add_section_period_3_end_time
        )
        let period1Days = this.convertToDaysInteger(this.add_section_period_1_days)
        let period1StartTime = this.convertToDatabaseTime(this.add_section_period_1_start_time)
        let period1EndTime = this.convertToDatabaseTime(this.add_section_period_1_end_time)

        let period2Days = this.convertToDaysInteger(this.add_section_period_2_days)
        let period2StartTime = this.convertToDatabaseTime(this.add_section_period_2_start_time)
        let period2EndTime = this.convertToDatabaseTime(this.add_section_period_2_end_time)

        let period3Days = this.convertToDaysInteger(this.add_section_period_3_days)
        let period3StartTime = this.convertToDatabaseTime(this.add_section_period_3_start_time)
        let period3EndTime = this.convertToDatabaseTime(this.add_section_period_3_end_time)
       
        axios.post(`${url}/api/v0/setup/addSection`, 
        {
          Course_Reference_Number: this.add_section_CRN, 
          Section_Number: this.add_section_number,

          Meeting_Period_1_Days: period1Days,
          Meeting_Period_1_Start: period1StartTime,
          Meeting_Period_1_End: period1EndTime,

          Meeting_Period_2_Days: period2Days,
          Meeting_Period_2_Start: period2StartTime,
          Meeting_Period_2_End: period2EndTime,

          Meeting_Period_3_Days: period3Days,
          Meeting_Period_3_Start: period3StartTime,
          Meeting_Period_3_End: period3EndTime

        }, { headers: { Authorization: `Bearer ${localStorage.getItem('token')}`}})
        .then((response) => 
        {
          console.log(response)
          this.getSections()
        })     
      },

      onModifySection()
      {
        var url = ''
        if (process.env.NODE_ENV === 'development') {
          url = 'http://localhost:3333'
        } 
        else {
          url = 'https://test-adoni.herokuapp.com'
        }

        const CRN = document.getElementById("modify_section_CRN").value
        const sectionNumber = document.getElementById("modify_section_number").value
        const days1 = this.convertToDaysInteger(document.getElementById("modify_section_period_1_days").value)
        const startTime1 = this.convertToDatabaseTime(document.getElementById("modify_section_period_1_start_time").value)
        const endTime1 = this.convertToDatabaseTime(document.getElementById("modify_section_period_1_end_time").value)
        const days2 = this.convertToDaysInteger(document.getElementById("modify_section_period_2_days").value)
        const startTime2 = this.convertToDatabaseTime(document.getElementById("modify_section_period_2_start_time").value)
        const endTime2 = this.convertToDatabaseTime(document.getElementById("modify_section_period_2_end_time").value)
        const days3 = this.convertToDaysInteger(document.getElementById("modify_section_period_3_days").value)
        const startTime3 = this.convertToDatabaseTime(document.getElementById("modify_section_period_3_start_time").value)
        const endTime3 = this.convertToDatabaseTime(document.getElementById("modify_section_period_3_end_time").value)

        console.log(
            CRN, 
            sectionNumber, 
            days1, startTime1, endTime1,
            days2, startTime2, endTime2,
            days3, startTime3, endTime3
        )
       
        axios.post(`${url}/api/v0/setup/modify-section/` + currentSectionID, 
        {
          Course_Reference_Number: CRN, 
          Section_Number: sectionNumber,

          Meeting_Period_1_Days: days1,
          Meeting_Period_1_Start: startTime1,
          Meeting_Period_1_End: endTime1,

          Meeting_Period_2_Days: days2,
          Meeting_Period_2_Start: startTime2,
          Meeting_Period_2_End: endTime2,

          Meeting_Period_3_Days: days3,
          Meeting_Period_3_Start: startTime3,
          Meeting_Period_3_End: endTime3

        }, { headers: { Authorization: `Bearer ${localStorage.getItem('token')}`}})
        .then((response) => 
        {
          console.log(response)
          this.getSections()
        })     
      },

      //Section Importing
      createSectionTable() {
        const sectionDiv = document.querySelector('div.sections')
        let tableHeaders = ["ID", "CRN","Section Number", "Period 1", "Period 2", "Period 3",]
        while (sectionDiv.firstChild)
        {
          sectionDiv.removeChild(sectionDiv.firstChild);
        }

          let sectionTable = document.createElement('table')
          sectionTable.className = 'sectionTable'

          let sectionTableHead = document.createElement('thead')
          sectionTableHead.className = 'sectionTableHead'

          let sectionTableHeaderRow = document.createElement('tr')
          sectionTableHeaderRow.className = 'sectionTableHeaderRow'

        tableHeaders.forEach(header => {
          let sectionHeader = document.createElement('th')
          sectionHeader.innerText = header
          sectionHeader.style.textAlign = 'center'
          sectionHeader.style.padding = '10px'
          sectionTableHeaderRow.append(sectionHeader)
        })
        
        sectionTableHead.append(sectionTableHeaderRow)
        sectionTable.append(sectionTableHead)

        let sectionTableBody = document.createElement('tbody')
        sectionTableBody.className = 'sectionTable-Body'
        sectionTable.append(sectionTableBody)

        sectionDiv.append(sectionTable)
      },

      appendSections(singleSection) {
        var url = ''
        if (process.env.NODE_ENV === 'development') {
          url = 'http://localhost:3333'
        } 
        else {
          url = 'https://test-adoni.herokuapp.com'
        }

        const sectionTable = document.querySelector('.sectionTable')

        let sectionTableByBodyRow = document.createElement('tr')
        sectionTableByBodyRow.className = 'sectionTableByBodyRow'

        let sectionID = document.createElement('td')
        sectionID.innerText = singleSection.id
        sectionID.style.textAlign = 'center'

        let sectionCRN = document.createElement('td')
        sectionCRN.innerText = singleSection.Course_Reference_Number
        sectionCRN.style.textAlign = 'center'

        let sectionNumber = document.createElement('td')
        sectionNumber.innerText = singleSection.Section_Number
        sectionNumber.style.textAlign = 'center'

        let period1 = document.createElement('td')
        period1.style.textAlign = 'center'
        period1.style.width = '15em'

        let days1 = this.convertToDaysString(singleSection.Meeting_Period_1_Days)
        let startTime1 = this.convertToPrintedTime(singleSection.Meeting_Period_1_Start)
        let endTime1 = this.convertToPrintedTime(singleSection.Meeting_Period_1_End)
        if (singleSection.Meeting_Period_1_Days == undefined && singleSection.Meeting_Period_1_Start == undefined && singleSection.Meeting_Period_1_End == undefined)
        {
            period1.innerText = ""
        }
        else
        {
            period1.innerText = days1 + ": " + startTime1 + "-" + endTime1
        }

        let period2 = document.createElement('td')
        period2.style.textAlign = 'center'
        period2.style.width = '15em'

        let days2 = this.convertToDaysString(singleSection.Meeting_Period_2_Days)
        let startTime2 = this.convertToPrintedTime(singleSection.Meeting_Period_2_Start)
        let endTime2 = this.convertToPrintedTime(singleSection.Meeting_Period_2_End)
        if (singleSection.Meeting_Period_2_Days == undefined && singleSection.Meeting_Period_2_Start == undefined && singleSection.Meeting_Period_2_End == undefined)
        {
            period2.innerText = ""
        }
        else
        {
            period2.innerText = days2 + ": " + startTime2 + "-" + endTime2
        }

        let period3 = document.createElement('td')
        period3.style.textAlign = 'center'
        period3.style.width = '15em'

        let days3 = this.convertToDaysString(singleSection.Meeting_Period_3_Days)
        let startTime3 = this.convertToPrintedTime(singleSection.Meeting_Period_3_Start)
        let endTime3 = this.convertToPrintedTime(singleSection.Meeting_Period_3_End)
        if (singleSection.Meeting_Period_3_Days == undefined && singleSection.Meeting_Period_3_Start == undefined && singleSection.Meeting_Period_3_End == undefined)
        {
            period3.innerText = ""
        }
        else
        {
            period3.innerText = days3 + ": " + startTime3 + "-" + endTime3
        }

        
        let startTIme1_24hour = this.convertTo24HourTime(singleSection.Meeting_Period_1_Start)
        let endTime1_24hour = this.convertTo24HourTime(singleSection.Meeting_Period_1_End)
        let startTIme2_24hour = this.convertTo24HourTime(singleSection.Meeting_Period_2_Start)
        let endTime2_24hour = this.convertTo24HourTime(singleSection.Meeting_Period_2_End)
        let startTIme3_24hour = this.convertTo24HourTime(singleSection.Meeting_Period_3_Start)
        let endTime3_24hour = this.convertTo24HourTime(singleSection.Meeting_Period_3_End)

        //Modify Section Button
        let modifySectionButton = document.createElement("button")
        modifySectionButton.innerText = "Modify Section " + singleSection.id
        modifySectionButton.style.margin = "10px"
        modifySectionButton.className = "btn btn-primary"
        modifySectionButton.onclick = function () 
        {
          const modifySectionDialogBox = document.getElementById('modifySectionDialogBox')

          const CRNField = document.getElementById("modify_section_CRN")
          CRNField.value = singleSection.Course_Reference_Number

          const sectionNumberField = document.getElementById("modify_section_number")
          sectionNumberField.value = singleSection.Section_Number

          const daysField1 = document.getElementById("modify_section_period_1_days")
          daysField1.value = days1

          const startTimeField1 = document.getElementById("modify_section_period_1_start_time")
          startTimeField1.value = startTIme1_24hour

          const endTimeField1 = document.getElementById("modify_section_period_1_end_time")
          endTimeField1.value = endTime1_24hour

          const daysField2 = document.getElementById("modify_section_period_2_days")
          daysField2.value = days2

          const startTimeField2 = document.getElementById("modify_section_period_2_start_time")
          startTimeField2.value = startTIme2_24hour

          const endTimeField2 = document.getElementById("modify_section_period_2_end_time")
          endTimeField2.value = endTime2_24hour

          const daysField3 = document.getElementById("modify_section_period_3_days")
          daysField3.value = days3

          const startTimeField3 = document.getElementById("modify_section_period_3_start_time")
          startTimeField3.value = startTIme3_24hour

          const endTimeField3 = document.getElementById("modify_section_period_3_end_time")
          endTimeField3.value = endTime3_24hour

          currentSectionID = singleSection.id
          console.log(currentSectionID)

          modifySectionDialogBox.showModal()
        }

        //Delete Section Button
        let setup = this
        let deleteSectionButton = document.createElement("button")
        deleteSectionButton.innerText = "Delete Section " + singleSection.id
        deleteSectionButton.className = "btn btn-primary"
        deleteSectionButton.style.backgroundColor = "red"
        deleteSectionButton.style.border = "red"
        deleteSectionButton.onclick = function () {
          axios.delete(`${url}/api/v0/setup/delete-section/` + singleSection.id, { headers: { Authorization: `Bearer ${localStorage.getItem('token')}`}})
          .then((response) =>
          {
            console.log(response)
            setup.getSections()
          })
        }

        sectionTableByBodyRow.append(sectionID, sectionCRN, sectionNumber, period1, period2, period3, modifySectionButton, deleteSectionButton)
        sectionTable.append(sectionTableByBodyRow)
      },

      getSections() {
        var url = ''
        if (process.env.NODE_ENV === 'development') {
          url = 'http://localhost:3333'
        } 
        else {
          url = 'https://test-adoni.herokuapp.com'
        }
        fetch(`${url}/api/v0/setup/sections`, { headers: { Authorization: `Bearer ${localStorage.getItem('token')}`}})
        .then(res => res.json())
        .then(sections => {
          this.createSectionTable()

          for (const section of sections) {
            let sectionIndex = sections.indexOf(section) + 1
            console.log(section)
            this.appendSections(section, sectionIndex)
          }
        })
      },

    }
})

</script>