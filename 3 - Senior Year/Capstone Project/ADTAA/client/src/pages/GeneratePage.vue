<template>
<div class="row">
    <div class="col-md-6 offset-md-3">
           <div>
            <img alt="UALRlogo" src="../assets/ualr.png">
        
       <form>
           <table class="table">
  <thead>
    <tr>
      <th scope="col">Course Reference #</th>
      <th scope="col">Course Section #</th>
      <th scope="col">Class</th>
      <th scope="col">Instructor</th>
      <th scope="col">Time Period</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th scope="row"></th>
      <td>{{}}</td>
      <td>{{}}</td>
      <td>{{}}</td>
      <td>{{}}</td>
    </tr>
    <tr>
      <th scope="row"></th>
      <td>{{}}</td>
      <td>{{}}</td>
      <td>{{}}</td>
      <td>{{}}</td>
    </tr>
    <tr>
      <th scope="row"></th>
      <td>{{}}</td>
      <td>{{}}</td>
      <td>{{}}</td>
      <td>{{}}</td>
    </tr>
    <tr>
      <th scope="row"></th>
      <td>{{}}</td>
      <td>{{}}</td>
      <td>{{}}</td>
      <td>{{}}</td>
    </tr>
    <tr>
      <th scope="row"></th>
      <td>{{}}</td>
      <td>{{}}</td>
      <td>{{}}</td>
      <td>{{}}</td>
    </tr>
  </tbody>
</table>
           <div class="my-3">
               <!--<router-link class="nav-link" to="/homepage">-->
               <login-button type="submit" class="btn btn-primary" buttonText="select"></login-button>
           <!--</router-link>-->
           </div>
       </form>
    </div>
    </div>
</div>
</template>

<script>
import LoginButton from '../components/LogButton.vue';

export default ({
    name: "GeneratePage",
    components: {
        LoginButton,
    },
});
</script>