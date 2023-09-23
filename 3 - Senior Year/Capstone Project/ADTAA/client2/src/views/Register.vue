<template>
<div>
    <div style="background-color:#640309;">
        <img alt="UALRlogo" src="../assets/ualr.png">
    </div>
<div class="row">
    <div class="col-md-6 offset-md-3">
        <div>
        <div style="padding-top: 50px;">
            <h3>Register</h3>
            <hr />
        </div>
       <form @submit.prevent="onRegister()">
           <div class="form-group">
               <label>Email</label>
               <input type="email" class="form-control" v-model="email" required/>
               <div class="error" v-if="errors.email">{{errors.email}}</div>
           </div>
           <div class="form-group">
               <label>Username</label>
               <input type="text" class="form-control" v-model="username" required/>
               <div class="error" v-if="errors.username">{{errors.username}}</div>
           </div>
           <div class="form-group">
               <label>Password</label>
               <input type="password" class="form-control" v-model="password" required/>
               <div class="error" v-if="errors.password">{{errors.password}}</div>
           </div>

           <div class="my-3">
               <button type="submit" class="btn btn-primary">Register</button>
           </div>
       </form>
    </div>
    </div>
</div>
</div>
</template>
<script>
import axios from "axios";
export default ({
    name: "RegisterPage",
  data() {
      return {
          email: '',
          username: '',
          password: '',
          errors: {},
      };
  },
  methods: {
      onRegister() {
    var url = ''
    if (process.env.NODE_ENV === 'development') {
      url = 'http://localhost:3333'
    } else {
      url = 'https://test-adoni.herokuapp.com'
    }
          axios.post(
              `${url}/api/v0/auth/register`,
              {email: this.email, username:this.username, password: this.password}
          ).then((response) => {
               this.$router.push({path:'/homepage'});
              console.log(response);
          });
      },
  },
})
</script>
