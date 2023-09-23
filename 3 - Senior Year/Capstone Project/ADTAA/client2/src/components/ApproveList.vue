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
      <td scope="row">{{user.id}}</td>
      <td scope="row">{{user.username}}</td>
      <td scope="row">{{user.email}}</td>
    </tr>
    </tbody>
    </table>
       </form>
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
        var url = ''
    if (process.env.NODE_ENV === 'development') {
      url = 'http://localhost:3333'
    } else {
      url = 'https://test-adoni.herokuapp.com'
    }
        axios.get(`${url}/requests`)
        .then((resp)=>{
            this.list=resp.data.users;
            console.warn(resp.data.users)
        })
    }
})
</script>

<style>

</style>