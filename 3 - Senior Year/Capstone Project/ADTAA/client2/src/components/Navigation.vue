<style>
  .nav-link {
  cursor: pointer;
  transition: 0.3s;
}

/* Change background color of buttons on hover */
.nav-link:hover {
  background-color: #ddd;
}

/* Create an active/current tablink class */
.nav-link.router-link-active {
  background-color: #ccc;
}
</style>
<template>
    <nav class="navbar navbar-expand-lg navbar-light bg-light">
  <div class="container-fluid">
    <a class="navbar-brand" href="#">UALR</a>
    <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarNav" aria-controls="navbarNav" aria-expanded="false" aria-label="Toggle navigation">
      <span class="navbar-toggler-icon"></span>
    </button>
    <div class="collapse navbar-collapse" id="navbarNav">
      <ul class="navbar-nav">
        <li class="nav-item" v-if="!isLoggedIn">
          <router-link class="nav-link" to="/homepage">Home</router-link>
        </li>
        <li class="nav-item" v-if="!isLoggedIn">
          <router-link class="nav-link" to="/login">Login</router-link>
        </li>
        <li class="nav-item" v-if="!isLoggedIn">
          <router-link class="nav-link" to="/register">Register</router-link>
        </li>
        <li class="nav-item" v-if="isLoggedIn"> <!--Is this what's messing us up?-->
          <router-link class="nav-link" to="/homepage">Home</router-link>
        </li>
        <li class="nav-item">
          <router-link class="nav-link" to="/rootuserpage" v-if="role === 4">Register Approval</router-link>
        </li>
        <li class="nav-item">
          <router-link class="nav-link" to="/myschedule" v-if="role === 2 || role === 3 || role === 4">View Schedule</router-link>
        </li>
        <li class="nav-item">
          <router-link class="nav-link" to="/setup" v-if="(role === 3) || (role === 4)">Setup</router-link>
        </li>
        <li class="nav-item" v-if="showLogout">
          <button class="nav-link" @click="logout">Logout</button>
        </li>
      </ul>
    </div>
  </div>
</nav>
</template>

<script>
import { mapActions } from 'vuex';
import { mapState } from 'vuex';
export default ({
  name: 'Navigation-item',
  components: {
  },
  computed: {
    ...mapState('auth', ['role', 'showLogout', 'isLoggedIn'])
  },
  methods: {
    ...mapActions('auth', ['processLogout']),
    logout() {
      this.processLogout()
      localStorage.clear();
      this.$router.push("/login")
    },
  }
})
</script>