'use strict'
const algorithm = require('../../Models/algorithm')
const Database = use('Database')

function convertToDays(days)
{
    if (!(days === undefined))
    {
        switch(days)
        {
        case 16:
            return [algorithm.Day.M];
        case 24:
            return [algorithm.Day.M, algorithm.Day.T];
        case 20:
            return [algorithm.Day.M, algorithm.Day.W];
        case 18:
            return [algorithm.Day.M, algorithm.Day.R];
        case 17:
            return [algorithm.Day.M, algorithm.Day.F];
        case 8:
            return [algorithm.Day.T];
        case 12:
            return [algorithm.Day.T, algorithm.Day.W];
        case 10:
            return [algorithm.Day.T, algorithm.Day.R];
        case 9:
            return [algorithm.Day.T, algorithm.Day.F];
        case 4:
            return [algorithm.Day.W];
        case 6:
            return [algorithm.Day.W, algorithm.Day.R];
        case 5:
            return [algorithm.Day.W, algorithm.Day.F];
        case 2:
            return [algorithm.Day.R];
        case 3:
            return [algorithm.Day.R, algorithm.Day.F];
        case 1:
            return [algorithm.Day.F];
        }
    }
}

function convertToTime(time)
{
    let tempHour;
    let tempMinute;
    if (time.toString().length == 1 || time.toString().length == 2)
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
    return (new algorithm.Time(parseInt(tempHour), parseInt(tempMinute)));
}

class AssistantController 
{

    async scheduler({request}) 
    {
        const courseList = await Database
            .query()
            .from('courses')    
            .select('Course_Reference_Number', 'Department_Code', 'Course_Number', 'Course_Title',)
        
        const courseDisciplineList = await Database
            .query()
            .from('course_disciplines')
            .join('discipline_areas', 'course_disciplines.Discipline_ID', '=', 'discipline_areas.id')
            .select('Course_Reference_Number', 'Discipline_Area')

        const instructorList = await Database
            .query()
            .from('instructors')
            .select('Last_Name', 'Max_Course_Load')

        const instructorDisciplineList = await Database
            .query()
            .from('instructor_disciplines')
            .join('discipline_areas', 'instructor_disciplines.Discipline_ID', '=', 'discipline_areas.id')
            .join('instructors', 'instructor_disciplines.Instructor_ID', '=', 'instructors.id')
            .select('Last_Name', 'Discipline_Area')

        const sectionList = await Database
            .query()
            .from('sections')
            .select('Course_Reference_Number', 'Section_Number', 'Meeting_Period_1_Days', 'Meeting_Period_1_Start', 'Meeting_Period_1_End', 'Meeting_Period_2_Days', 'Meeting_Period_2_Start', 'Meeting_Period_2_End', 'Meeting_Period_3_Days', 'Meeting_Period_3_Start', 'Meeting_Period_3_End')

        const courses = [];
        const instructors = [];
        const sections = [];

        for (let i = 0; i < courseList.length; i++)
        {
            let tempCourse = new algorithm.Course(courseList[i].Course_Reference_Number, courseList[i].Department_Code, courseList[i].Course_Number, courseList[i].Course_Title);
            courses.push(tempCourse);
        }   
        for (let i = 0; i < courses.length; i++)
        {
            for (let j = 0; j < courseDisciplineList.length; j++)
            {
                if (courses[i].courseReferenceNumber == courseDisciplineList[j].Course_Reference_Number)
                    {
                        courses[i].courseDisciplines.push(courseDisciplineList[j].Discipline_Area);
                    }
            }
        }

        for (let i = 0; i < instructorList.length; i++)
        {
            let tempInstructor = new algorithm.Instructor(instructorList[i].Last_Name, instructorList[i].Max_Course_Load);
            instructors.push(tempInstructor);
        }
        for (let i = 0; i < instructors.length; i++)
        {
            for (let j = 0; j < instructorDisciplineList.length; j++)
            {
                if (instructors[i].lastName == instructorDisciplineList[j].Last_Name)
                    {
                        instructors[i].disciplineAreas.push(instructorDisciplineList[j].Discipline_Area);
                    }
            }
        }
        
        for (let i = 0; i < sectionList.length; i++)
        {
            for (let j = 0; j < courses.length; j++)
            {
                if (sectionList[i].Course_Reference_Number == courses[j].courseReferenceNumber)
                {
                    let tempSection = new algorithm.Section(courses[j], sectionList[i].Section_Number);
                    sections.push(tempSection);
                }
            }
        }

        for (let i = 0; i < sections.length; i++)
        {
            for (let j = 0; j < sectionList.length; j++)
            {
                if (i == j)
                {
                    let tempDay1 = [];
                    let startTime1;
                    let endTime1;

                    tempDay1 = convertToDays(sectionList[j].Meeting_Period_1_Days);
                    startTime1 = convertToTime(sectionList[j].Meeting_Period_1_Start);
                    endTime1 = convertToTime(sectionList[j].Meeting_Period_1_End);

                    let tempPeriods1 = new algorithm.Period(tempDay1, startTime1, endTime1);
                    sections[i].meetingTimes.push(tempPeriods1);

                    let tempDay2 = [];
                    let startTime2;
                    let endTime2;

                    tempDay2 = convertToDays(sectionList[j].Meeting_Period_2_Days);
                    if (!(tempDay2 === undefined))
                    {
                        startTime2 = convertToTime(sectionList[j].Meeting_Period_2_Start);
                        endTime2 = convertToTime(sectionList[j].Meeting_Period_2_End);

                        let tempPeriods2 = new algorithm.Period(tempDay2, startTime2, endTime2);
                        sections[i].meetingTimes.push(tempPeriods2);
                    }

                    let tempDay3 = [];
                    let startTime3;
                    let endTime3;

                    tempDay3 = convertToDays(sectionList[j].Meeting_Period_3_Days);
                    if (!(tempDay3 === undefined))
                    {
                        startTime3 = convertToTime(sectionList[j].Meeting_Period_3_Start);
                        endTime3 = convertToTime(sectionList[j].Meeting_Period_3_End);

                        let tempPeriods3 = new algorithm.Period(tempDay3, startTime3, endTime3);
                        sections[i].meetingTimes.push(tempPeriods3);
                    }

                    break;
                }
            }
        }
        let tobeScheduled = new algorithm.PartialScheduleState();
        tobeScheduled.unassignedSections = sections;
        tobeScheduled.availableInstructors = instructors;


        return algorithm.schedulingAlgorithm(tobeScheduled);
    }
}

module.exports = AssistantController
