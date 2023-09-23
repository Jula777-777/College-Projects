"use strict";

//const InvalidAccessException = use("App/Exceptions/InvalidAccessException");


class Root {
  async handle({ request, auth }, next) {
    const user = await auth.getUser();
    console.log(user);
    if (!user.role || user.role != "4")
      //throw new InvalidAccessException();
      throw new Error('You Don\'t have clearance for this.');

     await next();
  }
}

module.exports = Root;