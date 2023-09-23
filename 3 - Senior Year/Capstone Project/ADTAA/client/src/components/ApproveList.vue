<template>
  <div>
      <form>
           <table class="table">
  <thead>
    <tr>
      <th scope="col">ID</th>
      <th scope="col">Username</th>
      <th scope="col">Email</th>
    </tr>
  </thead>
  <tbody>
    <tr v-for="user in list" v-bind:key="user.id" >
      <th scope="row"></th>
      <td>{{}}</td>
      <td>{{}}</td>
      <td>{{}}</td>
    </tr>
    </tbody>
    </table>
       </form>
      <!-- <table border= 1>
          <tr border= 1>
                <th>ID</th>
                <th>Username</th>
                <th>Email</th>
          </tr>
          <tr v-for="user in list" v-bind:key="user.id" border= 1>
                <td>{{user.id}}</td>
                <td>{{user.username}}</td>
                <td>{{user.email}}</td>
          </tr>
      </table> -->
  </div>
</template>

<script>
import axios from 'axios';
export default ({
    name: "ApproveList",
    data(){
        return{list: undefined}
    },
    mounted(){
        axios.get('http://localhost:3333/requests')
        .then((resp)=>{
            this.list=resp.data.users;
            console.warn(resp.data.users)
        })
    }
})
</script>

<style>

</style>