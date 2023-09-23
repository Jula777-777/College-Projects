<template>
  <div>
      <div style="background-color:#640309;">
        <img alt="UALRlogo" src="../assets/ualr.png">
    </div>

    <dialog id="errorMessage">
      <p>Invalid email or password.</p>
      <form>
        <button type="submit">OK</button>
      </form>
    </dialog>

    <div class="row">
      <div class="col-md-6 offset-md-3">
          <div>
          <div style="padding-top: 50px;">
              <h3>Login</h3>
              <hr />
          </div>
        <form @submit.prevent="onLogin">
            <div class="form-group">
                <label>Email</label>
                <input type="email" class="form-control" v-model="email" required/>
                <div class="error" v-if="errors.email">{{errors.email}}</div>
            </div>
            <div class="form-group">
                <label>Password</label>
                <input type="password" class="form-control" v-model="password" required/>
                <div class="error" v-if="errors.password">{{errors.password}}</div>
            </div>
            <div class="my-3">
                <login-button type="submit" class="btn btn-primary" buttonText="Login"></login-button>
            </div>
        </form>
      </div>
      </div>
  </div>
  </div>
</template>

<script>
import { mapActions } from 'vuex';
import LoginButton from '../components/LogButton.vue';
import axios from "axios";
export default ({
  name: "LoginPage",
  components: {
    LoginButton,
  },
  data() {
      return {
          email: '',
          password: '',
          errors: {},
      };
  },
  methods: {
    ...mapActions('auth', ['saveRoleToStore']),
      onLogin() {
          var url = ''
            if (process.env.NODE_ENV === 'development') {
                url = 'http://localhost:3333'
            } else {
                url = 'https://test-adoni.herokuapp.com'
            }
          
         axios.post(
               `${url}/api/v0/auth/login`,
              {email: this.email, password: this.password}
          ).then((response) => {
                if (response.data.token) {
                    localStorage.setItem('user', JSON.stringify(response.data));
                    localStorage.setItem('token', response.data.token.token);
                    localStorage.setItem('role', response.data.userRole[0].role);
                    this.saveRoleToStore(response.data.userRole[0].role);
                    axios.defaults.headers.common.Authorization = response.data.token.token
                       this.$router.push({path:'/homepage'});
                } 
          }
          ).catch(function(error) {
            console.log(error)
            const errorMessage = document.getElementById('errorMessage')
            errorMessage.showModal()
          });
          
      },
  },
});
</script>
