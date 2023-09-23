'use strict'

/** @type {typeof import('@adonisjs/lucid/src/Lucid/Model')} */
const Model = use('Model')

class Request extends Model {
    //populates the request_ques table
    static get table() {
        return 'request_ques'
      }
}

module.exports = Request
