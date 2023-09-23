'use strict'
const Database = use('Database')

class DevController {
    //listRoles
    async listRoles({request, response}){
        const list_roles = await Database
            .query()
            .from('roles')
            .select('id', 'role')
        return response.status(200).json({
            list_roles,
            message: 'Should be able to read the list'
        })
    }
}

module.exports = DevController
