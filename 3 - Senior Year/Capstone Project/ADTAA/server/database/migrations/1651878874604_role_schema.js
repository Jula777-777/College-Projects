'use strict'

/** @type {import('@adonisjs/lucid/src/Schema')} */
const Schema = use('Schema')
const Database = use('Database')

class RoleSchema extends Schema {
  up () {
    this.create('roles', (table) => {
      table.integer('id', 4).notNullable().unsigned().primary()
      table.string('role', 16).notNullable()
    })
    this.schedule(async (trx) => {
      const roles = ['Public User', 'Assistant', 'Admin', 'Root']
      await Promise.all(roles.map((role, i) => {
        return Database
          .table('roles')
          .transacting(trx)
          .insert({ role, id: i+1 })
      }))
    })
  }

  down () {
    this.drop('roles')
  }
}

module.exports = RoleSchema
