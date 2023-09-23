'use strict'

/** @type {import('@adonisjs/lucid/src/Schema')} */
const Schema = use('Schema')

class CourseDisciplineSchema extends Schema {
  up () {
    this.create('course_disciplines', (table) => {
      table.increments()
      table.integer('Course_Reference_Number', 60)
      table.integer('Discipline_ID', 60)
      table.timestamps()
    })
  }

  down () {
    this.drop('course_disciplines')
  }
}

module.exports = CourseDisciplineSchema
