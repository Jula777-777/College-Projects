'use strict'

const User = use('App/Models/User');
const Request = use('App/Models/Request');
const Database = use('Database')
class UserController {
    //Login method
    async login({request, auth, response }) {
        const { email, password } = request.all();
        const token = await auth.attempt(email, password);
        const userRole = await Database 
            .query()
            .from('users')
            .where('email', email)
            .select('role')
        return response.status(200).json({
            token,
            userRole
        });
    }

    //Register method
    async register({request, response}) {
        const {email, username, password} = request.all();
        console.log(email, username, password) //prints data to console
        const userRequest = await Request.create({ //instead of creating a User, create a Request
            email,
            username, //can set this to email if we want: username: email,
            password,
        });
        return response.status(200).json({ 
            userRequest,
            message: 'Yup this is returning',
        });
    }

    async devRegister({request, response}){
        const {email, username, password, role} = request.all();
        console.log(email, username, password, role) //prints data to console
        const devRequest = await User.create({ //instead of creating a User, create a Request
            email,
            username, //can set this to email if we want: username: email,
            password,
            role
        });
        return response.status(200).json({ 
            devRequest,
            message: 'Welcome back Captain.',
        });
    }

    async listUsers({request, response}){
        const list_users = await Database
            .query()
            .from('users')
            .select('id', 'username', 'email')
        return response.status(200).json({
            list_users,
        })
    }
}

module.exports = UserController
