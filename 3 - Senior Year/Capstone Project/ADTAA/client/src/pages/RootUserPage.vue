<template>
    <body>
        <div class="row">
    <div class="col-md-6 offset-md-3">
        <div>
            <img alt="UALRlogo" src="../assets/ualr.png">
       <table>
           <div>
               <ApproveList/>
           </div>
       </table>
    <div>
            <h3>Registration Approval</h3>
            <hr />
        </div>
       <form @submit.prevent="onApprove()">
           <div class="form-group">
               <label>ID</label>
               <input type="ID" class="form-control" v-model="id"/>
           </div>
           <div class="form-group">
               <label>Role</label>
               <input type="text" class="form-control" v-model="role"/>
           </div>
           <div class="form-group">
               <label>Approve</label>
               <input type="checkbox" v-model="approve"/>
           </div>

           <div class="my-3">
               <button type="submit" class="btn btn-primary">Register</button>
           </div>
       </form>
    </div>
</div>
</div>
    </body>
</template>

<script>
import ApproveList from '../components/ApproveList.vue';
import axios from "axios";
export default ({
    name: "RootUserPage",
    components: {
        ApproveList,
    },
    data() {
        return {

        };
      },
      methods: {
    //       next() {
    // axios.get('http://localhost:3333/api/v0/requests')
    //   .then(response => {
    //      this.rows = response.data
    //   }) 
    //   .catch(error => console.log(error))
    //     },


    onApprove() {
          axios.post(
               'http://localhost:3333/api/v0/approval/' + this.id,
              {id: this.id, role: this.role, approve: this.approve},{
                    headers: {
                Authorization: `Bearer ${localStorage.getItem('token')}`
                }
              }
              
            
          ).then((response) => {
              console.log(response);
              //axios.defaults.headers.common['Authorization'] = 'Bearer ' + token;
          });
      },
    }
      
    });
    
</script>

<style>

</style>