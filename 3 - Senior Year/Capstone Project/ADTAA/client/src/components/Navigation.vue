<template>
    <nav class="navbar navbar-expand-lg navbar-light bg-light">
  <div class="container-fluid">
    <a class="navbar-brand" href="#">UALR</a>
    <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarNav" aria-controls="navbarNav" aria-expanded="false" aria-label="Toggle navigation">
      <span class="navbar-toggler-icon"></span>
    </button>
    <div class="collapse navbar-collapse" id="navbarNav">
      <ul class="navbar-nav">
        <li class="nav-item">
          <router-link class="nav-link" to="/app">Home</router-link>
        </li>
        <li class="nav-item">
          <router-link class="nav-link" to="/login">Login</router-link>
        </li>
        <li class="nav-item">
          <router-link class="nav-link" to="/register">Register</router-link>
        </li>
        <li class="nav-item">
          <router-link class="nav-link" to="/homepage">Home Page</router-link>
        </li>
        <li class="nav-item">
          <router-link class="nav-link" to="/rootuserpage">Register Approval</router-link>
        </li>
        <li class="nav-item" v-if="isScheduleAllowed">
          <router-link class="nav-link" to="/myschedule">View Schedule</router-link>
        </li>
        <li class="nav-item" v-if="isSetupAllowed">
          <router-link class="nav-link" to="/setup">Setup</router-link>
        </li>
        <li class="nav-item" v-if="showLogout">
          <router-link class="nav-link" to="#" @click="logout">Logout</router-link>
        </li>
      </ul>
    </div>
  </div>
</nav>
</template>

<script>
export default ({
  name: 'Navigation-item',
  components: {
  },
  data() {
    return {
      isScheduleAllowed: false,
      isSetupAllowed: false,
      showLogout: false
    }
  },
  methods: {
    logout() {
      localStorage.clear();
      setTimeout(() => {
        this.$router.push("/login")
      }, 2000);
    }
  },
  mounted() {
    if (localStorage.getItem('role')) {
      this.showLogout = true
    }
    var data = localStorage.getItem('role');
    console.log("User role", data)
    if (localStorage.getItem('role') === 4 || localStorage.getItem('role') === 3) {
      this.isSetupAllowed = true
    } else if (localStorage.getItem('role') === 2 || localStorage.getItem('role') === 3 || localStorage.getItem('role') === 4) {
      this.isScheduleAllowed = true
    } else {
      this.isScheduleAllowed = false
      this.isSetupAllowed = false
    }
  }
})
</script>