<template>
<body>
<div>
<Navigation />
<div class="container">
  <div class="row">
    <div class="col-md-6 offset-md-3">
      <div>
        <router-view></router-view>
      </div>
    </div>
  </div>
</div>
<div class="container">
<div class="row">
    <!-- <div class="col-md-6 offset-md-3"><b>
      Welcome to the ADTAA: Academic Department Teaching Assignment Assistant! Here you will have a schedule generated for you, or you will be able to edit the schedule yourselves.</b>
    </div> -->
  </div>
</div>
</div>
</body>
<UalrFooter />
</template>

<script>
import Navigation from './components/Navigation.vue';
import UalrFooter from './components/UalrFooter.vue'
export default ({
  name: 'App',
  components: {
    Navigation,
    UalrFooter,
  }
})
</script>

<style>
#body{
   margin-bottom: (height of your footer);
}
</style>
