import Validations from "./Validations";

export default class LoginValidations {
    constructor(username, password) {
        this.username = username;
        this.password = password;
    }

    checkValidations() {
        let errors = [];

        if (!Validations.checkUsername(this.username)) {
            errors['username'] = 'Username is invalid';
        }
        if (!Validations.checkEmail(this.email)) {
            errors['email'] = 'Email Address is invalid';
        }

        if (!Validations.minLength(this.password, 6)) {
            errors['password'] = 'Password is invalid';
        }

        return errors;
    }
}