<template>
    <body>
        <div class="my-3">
                  <div class="col-md-6 offset-md-3">
            <div>
            <img alt="UALRlogo" src="../assets/ualr.png">
                </div>
                 <router-link class="nav-link" to="/myschedule">
               <login-button type="submit" class="btn btn-primary" buttonText="View Your Schedule"></login-button>
                </router-link>
                </div>
           </div>
    </body>
          
</template>

<script>
import LoginButton from '../components/LogButton.vue';
export default ({
     name: "RootUserHomePage",
    components: {
        LoginButton,
    },

});
</script>

<style>

</style>