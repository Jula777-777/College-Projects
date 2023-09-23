'use strict'

/** @type {typeof import('@adonisjs/lucid/src/Lucid/Model')} */
const Model = use('Model')

class AddInstructor extends Model 
{
    static get table()
    {
        return 'instructors';
    }
}

module.exports = AddInstructor
