const EmailDiv = document.querySelector("div.ListRequest") // Find the ListRequest div in our html
let tableHeaders = ["ID", "Username", "Email"]
const createListRequestTable = () => {
while (EmailDiv.firstChild) EmailDiv.removeChild(EmailDiv.firstChild) // Remove all children from ListRequest div (if any)
let ListRequestTable = document.createElement('table') // Create the table itself
ListRequestTable.className = 'ListRequestTable'
let ListRequestTableHead = document.createElement('thead') // Creates the table header group element
ListRequestTableHead.className = 'ListRequestTableHead'
let ListRequestTableRow = document.createElement('tr') // Creates the row that will contain the headers
ListRequestTableRow.className = 'ListRequestTableRow'
// Will iterate over all the strings in the tableHeader array and will append the header cells to the table header row
tableHeaders.forEach(header => {
let EmailHeader = document.createElement('th') // Creates the current header cell during a specific iteration
EmailHeader.innerText = header
ListRequestTableRow.append(EmailHeader) // Appends the current header cell to the header row
})
ListRequestTableHead.append(ListRequestTableRow) // Appends the header row to the table header group element
ListRequestTable.append(ListRequestTableHead)
let ListRequestTableBody = document.createElement('tbody') // Creates the table body group element
ListRequestTableBody.className = "ListRequestTable-body"
ListRequestTable.append(ListRequestTableBody) // Appends the table body group element to the table
EmailDiv.append(ListRequestTable) // Appends the table to the ListRequest div
}
// The function below will accept a single Email and its index to create the ID
const appendEmails = (singleEmail, singleEmailIndex) => {
const ListRequestTable = document.querySelector('.ListRequestTable') // Find the table we created
let ListRequestTableBodyRow = document.createElement('tr') // Create the current table row
ListRequestTableBodyRow.className = 'ListRequestTableBodyRow'
// Lines 72-85 create the 5 column cells that will be appended to the current table row
let EmailRanking = document.createElement('td')
EmailRanking.innerText = singleEmailIndex
let usernameData = document.createElement('td')
usernameData.innerText = singleEmail.user.username
let EmailData = document.createElement('td')
EmailData.innerText = singleEmail.Email
ListRequestTableBodyRow.append(EmailRanking, usernameData, EmailData) // Append all 5 cells to the table row
ListRequestTable.append(ListRequestTableBodyRow) // Append the current row to the ListRequest table body
}
const getEmails = () => {
fetch('http://localhost:3333/api/v0/requests') // Fetch for all Emails. The response is an array of objects that is sorted in decreasing order
.then(res => res.json())
.then(Emails => {
createListRequestTable() // Clears ListRequest div if it has any children nodes, creates & appends the table
// Iterates through all the objects in the Emails array and appends each one to the table body
for (const Email of Emails) {
let EmailIndex = Emails.indexOf(Email) + 1 // Index of Email in Email array for ID (these are already sorted in the back-end)
appendEmails(Email, EmailIndex) // Creates and appends each row to the table body
}
})
}