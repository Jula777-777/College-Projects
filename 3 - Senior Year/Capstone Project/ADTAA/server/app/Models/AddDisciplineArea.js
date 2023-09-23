'use strict'

/** @type {typeof import('@adonisjs/lucid/src/Lucid/Model')} */
const Model = use('Model')

class AddDisciplineArea extends Model 
{
    static get table()
    {
        return 'instructor_disciplines';
    }
}

module.exports = AddDisciplineArea

