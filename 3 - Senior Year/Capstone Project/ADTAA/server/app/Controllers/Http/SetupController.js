'use strict'

const AddInstructor = use('App/Models/AddInstructor');
const AddDisciplineArea = use('App/Models/AddDisciplineArea')
const AddSection = use('App/Models/AddSection');
const AddCourse = use('App/Models/AddCourse');
const AddCourseDiscipline = use('App/Models/AddCourseDiscipline')
const Database = use('Database')

class SetupController {
    async setup({request}) {
        return 'Some test';
    }

    async addSection({request}) {
        const {
            Course_Reference_Number, 
            Section_Number,

            Meeting_Period_1_Days,
            Meeting_Period_1_Start,
            Meeting_Period_1_End,

            Meeting_Period_2_Days,
            Meeting_Period_2_Start,
            Meeting_Period_2_End,

            Meeting_Period_3_Days,
            Meeting_Period_3_Start,
            Meeting_Period_3_End
        } = request.all();

        //prints data to console
        console.log( Course_Reference_Number, Section_Number, Meeting_Period_1_Days, Meeting_Period_1_Start, Meeting_Period_1_End,
                     Meeting_Period_2_Days,Meeting_Period_2_Start,Meeting_Period_2_End, 
                     Meeting_Period_3_Days, Meeting_Period_3_Start, Meeting_Period_3_End) 

        let userSection;
        if (!(Course_Reference_Number == undefined && Section_Number == undefined && Meeting_Period_1_Days == undefined && Meeting_Period_1_Start == undefined && Meeting_Period_1_End == undefined && Meeting_Period_2_Days == undefined && Meeting_Period_2_Start == undefined && Meeting_Period_2_End == undefined && Meeting_Period_3_Days == undefined && Meeting_Period_3_Start == undefined && Meeting_Period_3_End == undefined))
        {
            userSection = await AddSection.create({ //instead of creating a User, create a Request
                Course_Reference_Number, 
                Section_Number,

                Meeting_Period_1_Days,
                Meeting_Period_1_Start,
                Meeting_Period_1_End,

                Meeting_Period_2_Days,
                Meeting_Period_2_Start,
                Meeting_Period_2_End,

                Meeting_Period_3_Days,
                Meeting_Period_3_Start,
                Meeting_Period_3_End
            });
        }   
        return { 
            userSection,
            message: 'Thank you for your input',
        };
    }

    async addInstructor({request}) 
    {
        const {Last_Name, Max_Course_Load} = request.all();
        console.log(Last_Name, Max_Course_Load);

        let userInstructor;
        if (!(Last_Name == undefined && Max_Course_Load == undefined))
        {
            userInstructor = await AddInstructor.create(
                {
                    Last_Name,
                    Max_Course_Load,
                });
            }

        let userDisciplineArea1;
        let userDisciplineArea2;
        let userDisciplineArea3;
        let userDisciplineArea4;

        const{Discipline_ID_1} = request.all();
        console.log(Discipline_ID_1);
        if (Discipline_ID_1 != undefined)
        {
            userDisciplineArea1 = await AddDisciplineArea.create(
            {
                Instructor_ID : userInstructor.id, Discipline_ID : Discipline_ID_1 
            });
        }

        const{Discipline_ID_2} = request.all();
        console.log(Discipline_ID_2);
        if (Discipline_ID_2 != undefined)
        {
            userDisciplineArea2 = await AddDisciplineArea.create(
            {
                Instructor_ID : userInstructor.id, Discipline_ID : Discipline_ID_2 
            });
        }

        const{Discipline_ID_3} = request.all();
        console.log(Discipline_ID_3);
        if (Discipline_ID_3 != undefined)
        {
            userDisciplineArea3 = await AddDisciplineArea.create(
            {
                Instructor_ID : userInstructor.id, Discipline_ID : Discipline_ID_3 
            });
        }

        const{Discipline_ID_4} = request.all();
        console.log(Discipline_ID_4);
        if (Discipline_ID_4 != undefined)
        {
            userDisciplineArea4 = await AddDisciplineArea.create(
            {
                Instructor_ID : userInstructor.id, Discipline_ID : Discipline_ID_4 
            });
        }     

        const DisciplineAreas = []
        if (Discipline_ID_1 != undefined)
        {
            DisciplineAreas.push(userDisciplineArea1)
        }
        if (Discipline_ID_2 != undefined)
        {
            DisciplineAreas.push(userDisciplineArea2)
        }
        if (Discipline_ID_3 != undefined)
        {
            DisciplineAreas.push(userDisciplineArea3)
        }
        if (Discipline_ID_4 != undefined)
        {
            DisciplineAreas.push(userDisciplineArea4)
        }

        return{ userInstructor, DisciplineAreas,  message: 'Thank you for your input'};  
    }   

    async addCourse({request}) {
        
        const {Course_Reference_Number, Department_Code, Course_Number, Course_Title} = request.all();
        console.log(Course_Reference_Number, Department_Code, Course_Number, Course_Title)

        let userCourse;
        if (!(Course_Reference_Number == undefined && Department_Code == undefined && Course_Number == undefined && Course_Title == undefined && Course_Title == undefined))
        {
            userCourse = await AddCourse.create({Course_Reference_Number, Department_Code, Course_Number, Course_Title});
        }

        let userDisciplineArea1;
        let userDisciplineArea2;
        let userDisciplineArea3;
        let userDisciplineArea4;

        const{Discipline_ID_1} = request.all();
        console.log(Discipline_ID_1);
        if (Discipline_ID_1 != undefined)
        {
            userDisciplineArea1 = await AddCourseDiscipline.create(
            {
                Course_Reference_Number : userCourse.Course_Reference_Number, Discipline_ID : Discipline_ID_1 
            });
        }

        const{Discipline_ID_2} = request.all();
        console.log(Discipline_ID_2);
        if (Discipline_ID_2 != undefined)
        {
            userDisciplineArea2 = await AddCourseDiscipline.create(
            {
                Course_Reference_Number : userCourse.Course_Reference_Number, Discipline_ID : Discipline_ID_2
            });
        }

        const{Discipline_ID_3} = request.all();
        console.log(Discipline_ID_3);
        if (Discipline_ID_3 != undefined)
        {
            userDisciplineArea3 = await AddCourseDiscipline.create(
            {
                Course_Reference_Number : userCourse.Course_Reference_Number, Discipline_ID : Discipline_ID_3
            });
        }

        const{Discipline_ID_4} = request.all();
        console.log(Discipline_ID_4);
        if (Discipline_ID_4 != undefined)
        {
            userDisciplineArea4 = await AddCourseDiscipline.create(
            {
                Course_Reference_Number : userCourse.Course_Reference_Number, Discipline_ID : Discipline_ID_4
            });
        }
        
        const DisciplineAreas = []
        if (Discipline_ID_1 != undefined)
        {
            DisciplineAreas.push(userDisciplineArea1)
        }
        if (Discipline_ID_2 != undefined)
        {
            DisciplineAreas.push(userDisciplineArea2)
        }
        if (Discipline_ID_3 != undefined)
        {
            DisciplineAreas.push(userDisciplineArea3)
        }
        if (Discipline_ID_4 != undefined)
        {
            DisciplineAreas.push(userDisciplineArea4)
        }

        return {userCourse, DisciplineAreas, message: 'Thank you for your input'};
    }

    async modifySection({request, params})
    {
        const {
            Course_Reference_Number, 
            Section_Number,

            Meeting_Period_1_Days,
            Meeting_Period_1_Start,
            Meeting_Period_1_End,

            Meeting_Period_2_Days,
            Meeting_Period_2_Start,
            Meeting_Period_2_End,

            Meeting_Period_3_Days,
            Meeting_Period_3_Start,
            Meeting_Period_3_End
        } = request.all();

        //prints data to console
        console.log( Course_Reference_Number, Section_Number, Meeting_Period_1_Days, Meeting_Period_1_Start, Meeting_Period_1_End,
                     Meeting_Period_2_Days,Meeting_Period_2_Start,Meeting_Period_2_End, 
                     Meeting_Period_3_Days, Meeting_Period_3_Start, Meeting_Period_3_End) 

        
        if (!(Course_Reference_Number == undefined && Section_Number == undefined && Meeting_Period_1_Days == undefined && Meeting_Period_1_Start == undefined && Meeting_Period_1_End == undefined && Meeting_Period_2_Days == undefined && Meeting_Period_2_Start == undefined && Meeting_Period_2_End == undefined && Meeting_Period_3_Days == undefined && Meeting_Period_3_Start == undefined && Meeting_Period_3_End == undefined))
        {
            await Database
                .query()
                .from('sections')
                .where('id', params.id)
                .update({
                    'Course_Reference_Number': Course_Reference_Number, 
                    'Section_Number': Section_Number, 
                    'Meeting_Period_1_Days': Meeting_Period_1_Days, 
                    'Meeting_Period_1_Start': Meeting_Period_1_Start,
                    'Meeting_Period_1_End' : Meeting_Period_1_End,
                    'Meeting_Period_2_Days' : Meeting_Period_2_Days,
                    'Meeting_Period_2_Start' : Meeting_Period_2_Start,
                    'Meeting_Period_2_End' : Meeting_Period_2_End,
                    'Meeting_Period_3_Days' : Meeting_Period_3_Days,
                    'Meeting_Period_3_Start' : Meeting_Period_3_Start,
                    'Meeting_Period_3_End' : Meeting_Period_3_End
                })
        }

        console.log("The row id: "+ params.id + " has been updated.")
        return{message: "Section_id: "+ params.id + " has been updated."}
    }

    async modifyInstructor({request, params})
    {
        const {Last_Name, Max_Course_Load} = request.all();
        console.log(Last_Name, Max_Course_Load);
        if (!(Last_Name == undefined && Max_Course_Load == undefined))
        {
            await Database
                .query()
                .from('instructors')
                .where('id', params.id)
                .update({'Last_Name': Last_Name, 'Max_Course_Load': Max_Course_Load})
        }

        const instructorDisciplines = await Database
            .query()
            .from('instructor_disciplines')
            .where('Instructor_ID', params.id)
            .select('id')
        console.log(instructorDisciplines)
        
        const{Discipline_ID_1} = request.all();
        console.log(Discipline_ID_1);
        if (Discipline_ID_1 != undefined)
        {
            if (instructorDisciplines[0] != undefined)
            {
            await Database
                .query()
                .from('instructor_disciplines')
                .where({'Instructor_ID': params.id, 'id': instructorDisciplines[0].id})
                .update({'Discipline_ID': Discipline_ID_1})
            }
            else
            {
                await AddDisciplineArea.create(
                {
                    Instructor_ID : params.id, Discipline_ID : Discipline_ID_1 
                });
            }
        }

        const{Discipline_ID_2} = request.all();
        console.log(Discipline_ID_2);
        if (Discipline_ID_2 != undefined)
        {
            if (instructorDisciplines[1] != undefined)
            {
            await Database
                .query()
                .from('instructor_disciplines')
                .where({'Instructor_ID': params.id, 'id': instructorDisciplines[1].id})
                .update({'Discipline_ID': Discipline_ID_2})
            }
            else
            {
                await AddDisciplineArea.create(
                {
                    Instructor_ID : params.id, Discipline_ID : Discipline_ID_2 
                });
            }
        }

        const{Discipline_ID_3} = request.all();
        console.log(Discipline_ID_3);
        if (Discipline_ID_3 != undefined)
        {
            if (instructorDisciplines[2] != undefined)
            {
            await Database
                .query()
                .from('instructor_disciplines')
                .where({'Instructor_ID': params.id, 'id': instructorDisciplines[2].id})
                .update({'Discipline_ID': Discipline_ID_3})
            }
            else
            {
                await AddDisciplineArea.create(
                {
                    Instructor_ID : params.id, Discipline_ID : Discipline_ID_3 
                });
            }
        }

        const{Discipline_ID_4} = request.all();
        console.log(Discipline_ID_4);
        if (Discipline_ID_4 != undefined)
        {
            if (instructorDisciplines[3] != undefined)
            {
            await Database
                .query()
                .from('instructor_disciplines')
                .where({'Instructor_ID': params.id, 'id': instructorDisciplines[3].id})
                .update({'Discipline_ID': Discipline_ID_4})
            }
            else
            {
                await AddDisciplineArea.create(
                {
                    Instructor_ID : params.id, Discipline_ID : Discipline_ID_4 
                });
            }
        }
        
            console.log("The row id: "+ params.id + " has been updated.")
            return{message: "Instructor_id: "+ params.id + " has been updated."}
        
    }

    async modifyCourse({request, params})
    {
        const {Course_Reference_Number, Department_Code, Course_Number, Course_Title} = request.all();
        console.log(Course_Reference_Number, Department_Code, Course_Number, Course_Title)

        if (!(Course_Reference_Number == undefined && Department_Code == undefined && Course_Number == undefined && Course_Title == undefined && Course_Title == undefined))
        {
            await Database
                .query()
                .from('courses')
                .where('Course_Reference_Number', params.CRN)
                .update({
                    'Course_Reference_Number': Course_Reference_Number,
                    'Department_Code': Department_Code,
                    'Course_Number': Course_Number,
                    'Course_Title': Course_Title
            })
        }

        const courseDisciplines = await Database   
            .query()
            .from('course_disciplines')
            .where('Course_Reference_Number', params.CRN)
            .select('id')
        console.log(courseDisciplines)

        const{Discipline_ID_1} = request.all();
        console.log(Discipline_ID_1);
        if (Discipline_ID_1 != undefined)
        {
            if (courseDisciplines[0] != undefined)
            {
                await Database
                    .query()
                    .from('course_disciplines')
                    .where({'Course_Reference_Number': params.CRN, 'id': courseDisciplines[0].id})
                    .update({'Course_Reference_Number': Course_Reference_Number, 'Discipline_ID': Discipline_ID_1})
            }
            else
            {
                await AddCourseDiscipline.create(
                {
                    Course_Reference_Number, Discipline_ID : Discipline_ID_1
                });
            }
        }

        const{Discipline_ID_2} = request.all();
        console.log(Discipline_ID_2);
        if (Discipline_ID_2 != undefined)
        {
            if (courseDisciplines[1] != undefined)
            {
                await Database
                    .query()
                    .from('course_disciplines')
                    .where({'Course_Reference_Number': params.CRN, 'id': courseDisciplines[1].id})
                    .update({'Course_Reference_Number': Course_Reference_Number, 'Discipline_ID': Discipline_ID_2})
            }
            else
            {
                await AddCourseDiscipline.create(
                {
                    Course_Reference_Number, Discipline_ID : Discipline_ID_2
                });
            }
        }

        const{Discipline_ID_3} = request.all();
        console.log(Discipline_ID_3);
        if (Discipline_ID_3 != undefined)
        {
            if (courseDisciplines[2] != undefined)
            {
                await Database
                    .query()
                    .from('course_disciplines')
                    .where({'Course_Reference_Number': params.CRN, 'id': courseDisciplines[2].id})
                    .update({'Course_Reference_Number': Course_Reference_Number, 'Discipline_ID': Discipline_ID_3})
            }
            else
            {
                await AddCourseDiscipline.create(
                {
                    Course_Reference_Number, Discipline_ID : Discipline_ID_3
                });
            }
        }

        const{Discipline_ID_4} = request.all();
        console.log(Discipline_ID_4);
        if (Discipline_ID_4 != undefined)
        {
            if (courseDisciplines[3] != undefined)
            {
                await Database
                    .query()
                    .from('course_disciplines')
                    .where({'Course_Reference_Number': params.CRN, 'id': courseDisciplines[3].id})
                    .update({'Course_Reference_Number': Course_Reference_Number, 'Discipline_ID': Discipline_ID_4})
            }
            else
            {
                await AddCourseDiscipline.create(
                {
                    Course_Reference_Number, Discipline_ID : Discipline_ID_4
                });
            }
        }


        console.log("The row id: "+ params.CRN + " has been updated.")
        return{message: "Course_id: "+ params.CRN + " has been updated."}
    }

    async deleteSection({request, params, response}) {
        await Database
            .query()
            .from('sections')
            .where('id', params.id)
            .delete()
        console.log("The row id: "+ params.id + " has been deleted.")
        return response.status(200).json({
            message: "Section_id: "+ params.id + " has been deleted."
        })
    }

    async deleteInstructor({request, params, response}) {
        await Database
            .query()
            .from('instructors')
            .where('id', params.id)
            .delete()

        await Database
            .query()
            .from('instructor_disciplines')
            .where('Instructor_ID', params.id)
            .delete()

        console.log("The row id: "+ params.id + " has been deleted.")
        return response.status(200).json({
            message: "Instructor_id: "+ params.id + " has been deleted."
        })
    }

    async deleteCourse({request, params}) {
        await Database
            .query()
            .from('courses')
            .where('Course_Reference_Number', params.CRN)
            .delete()

        await Database
            .query()
            .from('course_disciplines')
            .where('Course_Reference_Number', params.CRN)
            .delete()

        console.log("The row CRN: "+ params.CRN + " has been deleted.")
        return{message: "Course_CRN: "+ params.CRN + " has been deleted."}
    }

    async listSections({request}) {
        const sectionList = await Database
            .query()
            .from('sections')
            .select('id', 'Course_Reference_Number', 'Section_Number','Meeting_Period_1_Days','Meeting_Period_1_Start','Meeting_Period_1_End',
            'Meeting_Period_2_Days','Meeting_Period_2_Start','Meeting_Period_2_End','Meeting_Period_3_Days','Meeting_Period_3_Start','Meeting_Period_3_End')
        return sectionList;
    }
    
    async listInstructors({request, response}) {
        const instructorList = await Database
            .query()
            .from('instructors')
            .select('id', 'Last_Name', 'Max_Course_Load')

        const instructorDisciplineList = await Database
            .query()
            .from('instructor_disciplines')
            .join('discipline_areas', 'instructor_disciplines.Discipline_ID', '=', 'discipline_areas.id')
            .join('instructors', 'instructor_disciplines.Instructor_ID', '=', 'instructors.id')
            .select('Last_Name', 'Discipline_Area')

        for (let i = 0; i < instructorList.length; i++)
        {
            let disciplineNumber = 1;
            for (let j = 0; j < instructorDisciplineList.length; j++)
            {
                if (instructorList[i].Last_Name == instructorDisciplineList[j].Last_Name)
                    {
                        instructorList[i]["Discipline_Area"+(disciplineNumber)] = instructorDisciplineList[j].Discipline_Area;
                        disciplineNumber++;
                    }
            }
        }

        return instructorList;
    }

    async listCourses({request}) {
        const courseList = await Database
            .query()
            .from('courses')
            .select('id', 'Course_Reference_Number', 'Department_Code', 'Course_Number', 'Course_Title')

        const courseDisciplineList = await Database
            .query()
            .from('course_disciplines')
            .join('discipline_areas', 'course_disciplines.Discipline_ID', '=', 'discipline_areas.id')
            .select('Course_Reference_Number', 'Discipline_Area')

        for (let i = 0; i < courseList.length; i++)
        {
            let disciplineNumber = 1;
            for (let j = 0; j < courseDisciplineList.length; j++)
            {
                if (courseList[i].Course_Reference_Number == courseDisciplineList[j].Course_Reference_Number)
                    {
                        courseList[i]["Discipline_Area"+(disciplineNumber)] = courseDisciplineList[j].Discipline_Area;
                        disciplineNumber++;
                    }
            }
        }

        return courseList;
    }
}


module.exports = SetupController
