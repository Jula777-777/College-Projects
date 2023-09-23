'use strict'

/** @type {typeof import('@adonisjs/lucid/src/Lucid/Model')} */
const Model = use('Model')

class AddCourse extends Model 
{
    static get table()
    {
        return 'courses';
    }
}

module.exports = AddCourse
