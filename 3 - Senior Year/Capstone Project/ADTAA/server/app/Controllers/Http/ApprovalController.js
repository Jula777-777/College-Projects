'use strict'
//import Database from '@ioc:Adonis/Lucid/Database'
const User = use('App/Models/User');
const Database = use('Database')
class ApprovalController {
    //display a list of requests for approval
    async listRequests({request, response}){
        const users = await Database
            .query()
            .from('request_ques')
            .select('id', 'username', 'email')
        return response.status(200).json({
            users,
        })
    }

    async approveRegistration({request, response, params}) {
        console.log('Top of approval building')
        const requestUser = await Database
            .query()
            .from('request_ques')
            .where('id', params.id)
            .select('username', 'email', 'password')
        const {approve, role} = request.all();
        console.log('Some text:', request.all())
        console.log('requestlength', requestUser.length)
        //checking to see if array is populated
        if(requestUser.length !== 1) {

            return response.status(404).json({
                message: 'Not found',
                status: 404
            })  
        }
        const user = requestUser[0]

        let newUser;
        if(approve){
            console.log('We are in the approve block')
            newUser = await User.create({ //creates user profile in database
                email: user.email,
                username: user.username, //can set this to email if we want: username: email,
                password: user.password,
                role
            });

            // const Mail = use('Mail')
            // await Mail.send('emails.welcome', {username}, (message) => {
            //     console.log('The entire object: ' + username)
            //     message.from('memory.adtaa@gmail.com')
            //     message.to(newUser.email)
            //     console.log('Attempting to call email here: ' + newUser.email)
            //     .subject('Welcome to ADTAA')
            // })
        }
        await Database
            .query()
            .from('request_ques')
            .where('id', params.id)
            .delete()
        return response.status(200).json({ 
            user: newUser,
            message: 'We hitting this at all?',
        });
    }
    
}

    

module.exports = ApprovalController
