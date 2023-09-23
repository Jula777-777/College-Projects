<template>
<body>
  <div style="background-color:#640309;">
        <img alt="UALRlogo" src="../assets/ualr.png">
    </div>
  <div class="row">
    <div class="col-md-6 offset-md-3">
    </div>
</div>
  <div class="title" style="padding: 25px; padding-left: 35px; width: 30%;">  
    <h3 style="">Schedule</h3>
    <hr>
  </div>
<center>
<div style="padding-top: 50px;" class='schedule'></div>
<br>
</center>
</body>
</template>

<script>
export default ({
  name: "MySchedule",
  data() {
      return {
      };
  },
  mounted: function() {
      this.$nextTick(function () 
      {
        console.log("HI")
        this.getSchedules()
      })
  },
  methods: {
    convertToDaysString(days)
      {
        console.log("made it")
        let daysString = ""
        for (let i = 0; i < days.length; i++)
        {
          if (i > 0)
          {
            daysString += "/"
          }
          if (days[i] != undefined)
          {
          switch(days[i])
            {
              case 1:
                daysString += "Mon";
                break;
              case 2:
                daysString += "Tues";
                break;
              case 3:
                daysString += "Wed";
                break;
              case 4:
                daysString += "Thurs";
                break;
              case 5:
                daysString += "Fri";
                break;
            }
          }
        } 
        console.log(daysString)
        return daysString
      },
      convertToPrintedTime(time)
      {
          let tempHour = time.hour;
          let tempMinute = time.minute;
          let pmOrAm
          if (time == undefined)
          {
              return ("???")
          }

          if (tempMinute.toString().length == 1)
          {
            tempMinute = "0" + tempMinute
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
          console.log(tempHour)
          console.log(tempMinute)
          return (tempHour +":" + tempMinute + pmOrAm);
      },

      createScheduleTable() {
        const scheduleDiv = document.querySelector('div.schedule')
        let tableHeaders = ["CRN", "Section Number", "Course Title", "Period 1", "Period 2", "Period 3", "Instructor"]
        
        while (scheduleDiv.firstChild)
        {
          scheduleDiv.removeChild(scheduleDiv.firstChild);
        }

          let scheduleTable = document.createElement('table')
          scheduleTable.className = 'scheduleTable'

          let scheduleTableHead = document.createElement('thead')
          scheduleTableHead.className = 'scheduleTableHead'

          let scheduleTableHeaderRow = document.createElement('tr')
          scheduleTableHeaderRow.className = 'scheduleTableHeaderRow'

        tableHeaders.forEach(header => {
          let scheduleHeader = document.createElement('th')
          scheduleHeader.innerText = header
          scheduleHeader.style.textAlign = 'center'
          scheduleHeader.style.padding = '10px'
          scheduleTableHeaderRow.append(scheduleHeader)
        })
        
        scheduleTableHead.append(scheduleTableHeaderRow)
        scheduleTable.append(scheduleTableHead)

        let scheduleTableBody = document.createElement('tbody')
        scheduleTableBody.className = 'scheduleTable-Body'
        scheduleTable.append(scheduleTableBody)

        scheduleDiv.append(scheduleTable)
      },

      appendSections(singleSection) {
        const scheduleTable = document.querySelector('.scheduleTable')

        let scheduleTableByBodyRow = document.createElement('tr')
        scheduleTableByBodyRow.className = 'scheduleTableByBodyRow'

        let sectionCRN = document.createElement('td')
        sectionCRN.innerText = singleSection.section.course.courseReferenceNumber;
        sectionCRN.style.textAlign = 'center'

        let section_Number = document.createElement('td')
        section_Number.innerText = singleSection.section.sectionNumber
        section_Number.style.textAlign = 'center'

        let sectionCourseTitle = document.createElement('td')
        sectionCourseTitle.innerText = singleSection.section.course.courseTitle
        sectionCourseTitle.style.textAlign = 'center'
        sectionCourseTitle.style.width = '25em'

        let period1 = document.createElement('td')
        period1.style.textAlign = 'center'
        period1.style.width = '15em'

        let period2 = document.createElement('td')
        period2.style.textAlign = 'center'
        period2.style.width = '15em'

        let period3 = document.createElement('td')
        period3.style.textAlign = 'center'
        period3.style.width = '15em'
        
        for (let i = 0; i < singleSection.section.meetingTimes.length; i++)
        {
          if (singleSection.section.meetingTimes[i] != undefined)
          {
            if (i == 0)
            {
              let days1 = this.convertToDaysString(singleSection.section.meetingTimes[0].days)
              let startTime1 = this.convertToPrintedTime(singleSection.section.meetingTimes[0].startTime)
              let endTime1 = this.convertToPrintedTime(singleSection.section.meetingTimes[0].endTime)
              period1.innerText = days1 + ": " + startTime1 + "-" + endTime1
              console.log(singleSection.section.course.courseReferenceNumber)
            }
            else if (i == 1)
            {
              let days2 = this.convertToDaysString(singleSection.section.meetingTimes[1].days)
              let startTime2 = this.convertToPrintedTime(singleSection.section.meetingTimes[1].startTime)
              let endTime2 = this.convertToPrintedTime(singleSection.section.meetingTimes[1].endTime)
              period2.innerText = days2 + ": " + startTime2 + "-" + endTime2
              console.log(singleSection.section.course.courseReferenceNumber)
            }
            else if (i == 2)
            {
              let days3 = this.convertToDaysString(singleSection.section.meetingTimes[2].days)
              let startTime3 = this.convertToPrintedTime(singleSection.section.meetingTimes[2].startTime)
              let endTime3 = this.convertToPrintedTime(singleSection.section.meetingTimes[2].endTime)
              period3.innerText = days3 + ": " + startTime3 + "-" + endTime3
              console.log(singleSection.section.course.courseReferenceNumber)
            }
          }
          else
          {
            if (i == 0)
            {
              period1.innerText = ""
            }
            else if (i == 1)
            {
              period2.innerText = ""
            }
            else if (i == 2)
            { 
              period3.innerText = ""
            }
          }
        }        

        let instructorName = document.createElement('td')
        instructorName.innerText = singleSection.instructor.lastName
        instructorName.style.textAlign = 'center'
        instructorName.style.width = '10em'

        scheduleTableByBodyRow.append(sectionCRN, section_Number, sectionCourseTitle, period1, period2, period3, instructorName)
        scheduleTable.append(scheduleTableByBodyRow)
      },

      getSchedules() {
        var url = ''
          if (process.env.NODE_ENV === 'development') {
            url = 'http://localhost:3333'
          } else {
            url = 'https://test-adoni.herokuapp.com'
          }
        fetch(`${url}/api/v0/assistant/scheduler`, { headers: { Authorization: `Bearer ${localStorage.getItem('token')}`}})
        .then(res => res.json())
        .then(sections => {
          this.createScheduleTable()

          for (const section of sections) {
            let sectionIndex = sections.indexOf(section) + 1
            console.log(section)
            this.appendSections(section, sectionIndex)
          }
        })
      }
      },
  })

</script>