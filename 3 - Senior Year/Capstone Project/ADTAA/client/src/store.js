import axios from 'axios'

import { createStore } from 'vuex'

const store = createStore({
    state: {
        user: null
    },
    mutations:
    {
        SET_USER_DATA(state, userData) {
            state.user = userData
            localStorage.setItem('user', JSON.stringify(userData))
            axios.defaults.headers.common['Authorization'] = `Bearer ${
                userData.token
            }`
            console.log(userData.token)
        }
    },
    actions: {
        login ({commit}, credentials) {
            return axios.post('http://localhost:3333/api/v0/auth/login', credentials)
                .then(({data}) => {
                    commit('SET_USER_DATA', data)
                })
        }
    }
})

export default store;


/*
import { createStore } from "vuex";
import auth from './store/modules/auth/index';
const store = createStore({
    modules: {
        auth,
    },
});

export default store;
*/