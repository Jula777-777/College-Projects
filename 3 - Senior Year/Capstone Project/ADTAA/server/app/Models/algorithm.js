const DisciplineArea =
{
    Programming_CPlusPlus: "Programming_CPlusPlus", 
    Programming_Python: "Programming_Python", 
    SoftwareEngineering: "SoftwareEngineering", 
    SoftwareDevelopmentMethodologies: "SoftwareDevelopmentMethodologies", 
    GameDevelopment: "GameDevelopment", 
    DataStructuresAndAlgorithms: "DataStructuresAndAlgorithms", 
    ComputerOrganization: "ComputerOrganization", 
    OperatingSystems: "OperatingSystems", 
    ProgrammingLanguages: "ProgrammingLanguages", 
    Cybersecurity: "Cybersecurity", 
    MobileApplications: "MobileApplications", 
    ArtificialIntelligence: "ArtificialIntelligence", 
    Networks: "Networks", 
    TheoryOfComputation: "TheoryOfComputation", 
    ParallelAndDistributedSystems: "ParallelAndDistributedSystems", 
    VirtualReality: "VirtualReality", 
    HardwareDesigns: "HardwareDesigns"
};

const Day = 
{
    M: 1, 
    T: 2, 
    W: 3,
    R: 4,
    F: 5
};

class Time
{
    constructor(hour, minute)
    {
        this.hour = hour;
        this.minute = minute;
    }
}

class Period
{
    constructor(days = [], startTime, endTime)
    {
        this.days = days;
        this.startTime = startTime;
        this.endTime = endTime;
    }
}

class Instructor
{
    constructor(lastName, maxLoad, disciplineAreas = [], meetingTimes = [])
    {
        this.lastName = lastName;
        this.maxLoad = maxLoad;
        this.disciplineAreas = disciplineAreas;
        this.classLoad = 0;
        this.meetingTimes = meetingTimes;
    }
}

class Course
{
    constructor(courseReferenceNumber, departmentCode, courseNumber, courseTitle, courseDisciplines = [])
    {
        this.courseReferenceNumber = courseReferenceNumber;
        this.departmentCode = departmentCode
        this.courseNumber = courseNumber;
        this.courseTitle = courseTitle;
        this.courseDisciplines = courseDisciplines;
    }
}

class Section
{
    constructor(course, sectionNumber, meetingTimes = [])
    {
        this.course = course;
        this.sectionNumber = sectionNumber;
        this.meetingTimes = meetingTimes;
        this.possibleInstructors = [];
    }
}

class ScheduledSection
{
    constructor(section, instructor)
    {
        this.section = section;
        this.instructor = instructor;
    }
}

class PartialScheduleState
{
    constructor()
    {
        this.partialSchedule = [];
        this.unassignedSections = [];
        this.availableInstructors = [];
    }
}

function time_greater_than(t1, t2)
{
    if (t1.hour > t2.hour)
    {
        return true;
    }
    if (t1.hour < t2.hour)
    {
        return false;
    }
    if (t1.minute >= t2.minute)
    {
        return true;
    }
    return false;
}

function time_less_than(t1, t2)
{
    if (t1.hour < t2.hour)
    {
        return true;
    }
    if (t1.hour > t2.hour)
    {
        return false;
    }
    if (t1.minute <= t2.minute)
    {
        return true;
    }
    return false;
}

function compare_periods(a,b)
    {
        if (a.days[0] != b.days[0])
        {
            return (a.days[0] - b.days[0]);
        }   
        if (a.startTime.hour != b.startTime.hour)
        {
            return (a.startTime.hour - b.startTime.hour);
        }
        return (a.startTime.minute - b.startTime.minute);
    }

function DisciplineAreasOverlap(set1, set2)
{
    for (let i  = 0; i < set1.length; i++)
    {
        for (let j = 0; j < set2.length; j++)
        {
            if (set1[i] == set2[j])
            {
                return true;
            }
        }
    }
    return false;

}

function doConflict(set1, set2)
{
    if (set1 === undefined || set1.length == 0 || set2 === undefined || set2.length == 0)
    {
        return false;
    }
    for (let p1 = 0; p1 < set1.length; p1++)
    {
        for (let p2 = 0; p2 < set2.length; p2++)
        {
            for (let d1 = 0; d1 < set1[p1].days.length; d1++)
            {
                for (let d2 = 0; d2 < set2[p2].days.length; d2++)
                {
                    if (set1[p1].days[d1] == set2[p2].days[d2])
                    {
                        if ((time_greater_than(set2[p2].startTime, set1[p1].startTime) && time_less_than(set2[p2].startTime, set1[p1].endTime)) || (time_greater_than(set1[p1].startTime, set2[p2].startTime) && time_less_than(set1[p1].startTime, set2[p2].endTime)))
                        {
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;

}

function schedulingAlgorithm(toBeScheduled)
{
    for (let i = 0; i < toBeScheduled.unassignedSections.length; i++)
    {
        for (let j = 0; j < toBeScheduled.availableInstructors.length; j++)
        {
            if (DisciplineAreasOverlap(toBeScheduled.unassignedSections[i].course.courseDisciplines, toBeScheduled.availableInstructors[j].disciplineAreas))
            {
                toBeScheduled.unassignedSections[i].possibleInstructors.push(toBeScheduled.availableInstructors[j]);
            }
        }
    }

    toBeScheduled.unassignedSections.sort(function(a, b) 
    {
        if (a.possibleInstructors.length == b.possibleInstructors.length)
        {
            if (a.meetingTimes.length > b.meetingTimes.length)
            {
                return -1;
            }
            else
            {
                return 1;
            }
        }   
        if (a.possibleInstructors.length < b.possibleInstructors.length)
        {
            return -1;
        }
        else
        {
            return 1;
        }
    });


    toBeScheduled.availableInstructors.sort(function(a, b)
    {
        if (a.lastName > b.lastName)
        {
            return -1;
        }
        else 
        {
            return 1;
        }
    });

    
    if (!(toBeScheduled.unassignedSections.length == 0) && !(toBeScheduled.availableInstructors.length == 0))
    {
        let j = 0;
        for (let i = 0; i < toBeScheduled.unassignedSections.length; i++)
        {
            for (j = 0; j < toBeScheduled.availableInstructors.length; j++)
            {
                if (!(doConflict(toBeScheduled.unassignedSections[i].meetingTimes, toBeScheduled.availableInstructors[j].meetingTimes)) && DisciplineAreasOverlap(toBeScheduled.unassignedSections[i].course.courseDisciplines, toBeScheduled.availableInstructors[j].disciplineAreas))
                {
                    toBeScheduled.availableInstructors[j].classLoad++;
                    for (let k = 0; k < toBeScheduled.unassignedSections[i].meetingTimes.length; k++)
                    {
                        toBeScheduled.availableInstructors[j].meetingTimes.push(toBeScheduled.unassignedSections[i].meetingTimes[k]);
                    }
                    toBeScheduled.partialSchedule.push(new ScheduledSection(toBeScheduled.unassignedSections[i], toBeScheduled.availableInstructors[j]));
                    break;
                }
            }
            if (j < toBeScheduled.availableInstructors.length && toBeScheduled.availableInstructors[j].classLoad >= toBeScheduled.availableInstructors[j].maxLoad)
            {
                toBeScheduled.availableInstructors.splice(j, 1);
            }
        }
    }

    for (let i = 0; i < toBeScheduled.partialSchedule.length; i++)
    {
        let k = 0;
        for (k = 0; k < toBeScheduled.unassignedSections.length; k++)
        {
            if (toBeScheduled.partialSchedule[i].section == toBeScheduled.unassignedSections[k]);
            {
                break;
            }
        }
        if (k < toBeScheduled.unassignedSections.length)
        {
            toBeScheduled.unassignedSections.splice(k, 1);
        }
    } 

    for (let i = 0; i < toBeScheduled.partialSchedule.length; i++)
    {
        toBeScheduled.partialSchedule[i].section.meetingTimes.sort(compare_periods);

        toBeScheduled.partialSchedule[i].instructor.meetingTimes.sort(compare_periods);
    }

    toBeScheduled.partialSchedule.sort(function(a, b)
    {
        if (a.section.course.courseReferenceNumber == b.section.course.courseReferenceNumber)
        {
            return (a.section.sectionNumber - b.section.sectionNumber);
        }
        return (a.section.course.courseReferenceNumber - b.section.course.courseReferenceNumber);
    });

    return toBeScheduled.partialSchedule;
}

module.exports = {schedulingAlgorithm, DisciplineArea, Day, Time, Period, Instructor, Course, Section, ScheduledSection, PartialScheduleState};