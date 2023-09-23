"use strict";

//const InvalidAccessException = use("App/Exceptions/InvalidAccessException");


class Admin {
  async handle({ request, auth }, next) {
    const user = await auth.getUser();
    console.log(user);
    if (!user.role || (user.role != "3" && user.role != '4'))
      //throw new InvalidAccessException();
      throw new Error('You stumbled into the wrong neighborhood punk.');

     await next();
  }
}

module.exports = Admin;