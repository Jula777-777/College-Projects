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
          <router-link class="nav-link" to="/homepage">Home Page</router-link>
        </li>
        <!-- <li class="nav-item">
          <router-link class="nav-link" to="/rootuserpage">Register Approval</router-link>
        </li> -->
        <li class="nav-item">
          <router-link class="nav-link" to="/myschedule" v-if="localStorage.getItem('role') === 2 || localStorage.getItem('role') === 3 || localStorage.getItem('role') === 4">View Schedule</router-link>
        </li>
        <li class="nav-item" v-if="localStorage.getItem('role') === 4 || localStorage.getItem('role') === 3">
          <router-link class="nav-link" to="/setup">Setup</router-link>
        </li>
      </ul>
    </div>
  </div>
</nav>
</template>

<script>
export default ({
  name: 'NewNavigation-item',
  components: {
  }
})
</script>