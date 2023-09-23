<template>
<div>
<div style="background-color:#640309;">
        <img alt="UALRlogo" src="../assets/ualr.png">
    </div>
<div id="container" style="width:100%; padding-top: 50px;">                                   
    <div id="left" style="float:left; width:50%;">
    <center>
        <table>
           <div>
                <ApproveList/>
            </div> 
       </table>
    </center>
    </div>
    
    <dialog id="errorMessage">
        <p>Your input is invalid. Please input a valid ID and a role.</p>
        <form>
            <button type="submit">OK</button>
        </form>
    </dialog>

    <div id="right" style="float:right; width:50%;">
        <div> 
            <h3>Registration Approval</h3>
            <hr />
            <form @submit.prevent="onApprove()">
           <div class="form-group">
               <label>ID</label>
               <input type="text" class="form-control" v-model="id"/>
           </div>
           <div class="form-group">
               <label>Role</label>
               <input type="text" class="form-control" v-model="role"/>
           </div>

           <div class="my-3">
               <button type="submit" class="btn btn-primary">Approve</button>
               <button type="button" class="btn btn-primary" style="border: red; background-color:red; margin-left: 10px" @click="onDeny()">Deny</button>
           </div>
       </form>
        </div>
    </div>                   
</div>
<div style="padding:150px"></div>
</div>
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
            id: '',
            role: '',
            approve: '',
        };
      },
      methods: {
    onApprove() {
        var url = ''
        if (process.env.NODE_ENV === 'development') {
        url = 'http://localhost:3333'
        } 
        else {
        url = 'https://test-adoni.herokuapp.com'
        }
        axios.post(`${url}/api/v0/approval/${this.id}`,
            {id: this.id, role: this.role, approve: true},{
                headers: {
            Authorization: `Bearer ${localStorage.getItem('token')}`
            },
            }    
        ).then((response) => {
            window.location.reload();
            console.log(response);
        }
        ).catch(function(error) {
            console.log(error)
            const errorMessage = document.getElementById('errorMessage')
            errorMessage.showModal()
          });
      },
      onDeny()
      {
        console.log('hi')
        var url = ''
        if (process.env.NODE_ENV === 'development') {
        url = 'http://localhost:3333'
        } 
        else {
        url = 'https://test-adoni.herokuapp.com'
        }
        axios.post(`${url}/api/v0/approval/${this.id}`,
            {id: this.id, role: this.role, approve: false},{
                headers: {
            Authorization: `Bearer ${localStorage.getItem('token')}`
            },
            }    
        ).then((response) => {
            window.location.reload();
            console.log(response);
        }
        ).catch(function(error) {
            console.log(error)
            const errorMessage = document.getElementById('errorMessage')
            errorMessage.showModal()
          });
      }
    }
      
    });
    
</script>

<style>

</style>