'use strict'

/** @type {typeof import('@adonisjs/lucid/src/Lucid/Model')} */
const Model = use('Model')

class AddSection extends Model {
        //populates the request_ques table
        static get table() {
            return 'sections'
          }
}

module.exports = AddSection
