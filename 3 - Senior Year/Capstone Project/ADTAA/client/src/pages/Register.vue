<template>
<div class="row">
    <div class="col-md-6 offset-md-3">
        <div>
            <img alt="UALRlogo" src="../assets/ualr.png">
        <div>
            <h3>Register</h3>
            <hr />
        </div>
       <form @submit.prevent="onRegister()">
           <div class="form-group">
               <label>Email</label>
               <input type="text" class="form-control" v-model="email" />
               <div class="error" v-if="errors.email">{{errors.email}}</div>
           </div>
           <div class="form-group">
               <label>Username</label>
               <input type="text" class="form-control" v-model="username" />
               <div class="error" v-if="errors.username">{{errors.username}}</div>
           </div>
           <div class="form-group">
               <label>Password</label>
               <input type="password" class="form-control" v-model="password" />
               <div class="error" v-if="errors.password">{{errors.password}}</div>
           </div>

           <div class="my-3">
               <button type="submit" class="btn btn-primary">Register</button>
           </div>
       </form>
    </div>
    </div>
</div>
</template>
<script>
//import LoginValidations from '../services/LoginValidations';
import axios from "axios";
export default ({
    name: "RegisterPage",
  data() {
      return {
          username: '',
          password: '',
          errors: {},
      };
  },
  methods: {
      onRegister() {
          axios.post(
              'http://localhost:3333/api/v0/auth/register',
              {email: this.email, username:this.username, password: this.password}
          ).then((response) => {
              console.log(response);
          });
      },
    // onLogin() {
    //       console.log('onLogin called')
    //        axios.get('http://jsonplaceholder.typicode.com/posts').then((response) => {
    //         console.log(response)
    //        })
    //         // axios.post('http://localhost:3333/auth/register', {
    //         //         "email": "testemail4@test.com",
    //         //         "password": "password4"
    //         //     }
    //         // ).then(response => {
    //         //     console.log(response)
    //         // })
    //     //   let validations = new LoginValidations(
    //     //       this.username, 
    //     //       this.password,
    //     //       );
    //     //     this.errors = validations.checkValidations();
    //     //     if ('emails' in this.errors || 'password' in this.errors) {
    //     //         return false;
    //     //     }
    //     // console.log('here')
    //   },
  },
})
</script>
