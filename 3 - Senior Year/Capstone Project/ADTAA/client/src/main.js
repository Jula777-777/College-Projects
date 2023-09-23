//import { sync } from 'vuex-router-sync';
import { createApp } from 'vue';
import App from './App.vue';
import router from './router';
import LoginValidations from './services/LoginValidations';
import store from './store';
import axios from 'axios';

//import UserController from '../server/app/Controllers/Http/UserController';
axios.defaults.headers.common['Content-Type'] = 'application/json'
const token = sessionStorage.getItem("token")
if (token) {
  axios.defaults.headers.common.Authorization = 'Bearer ' + token;
}

router.beforeEach((to, from, next) => {
  if (to.matched.some(record => record.meta.requiresRole4)) {
    if (localStorage.getItem('role') != 4) {
      next({
        path: '/'
      })
    } else {
      next()
    }
  } else {
    next()
  }
})

router.beforeEach((to, from, next) => {
  if (to.matched.some(record => record.meta.requiresRole3or4)) {
    if (localStorage.getItem('role') != 3 || localStorage.getItem('role') != 4) {
      next({
        path: '/'
      })
    } else {
      next()
    }
  } else {
    next()
  }
})

router.beforeEach((to, from, next) => {
  if (to.matched.some(record => record.meta.requiresRole3)) {
    if (localStorage.getItem('role') != 3) {
      next({
        path: '/'
      })
    } else {
      next()
    }
  } else {
    next()
  }
})

router.beforeEach((to, from, next) => {
  if (to.matched.some(record => record.meta.requiresRole2)) {
    if (localStorage.getItem('role') != 2) {
      next({
        path: '/'
      })
    } else {
      next()
    }
  } else {
    next()
  }
})

router.beforeEach((to, from, next) => {
  if (to.matched.some(record => record.meta.requiresRole1)) {
    if (localStorage.getItem('role') != 1) {
      next({
        path: '/'
      })
    } else {
      next()
    }
  } else {
    next()
  }
})

const app= createApp(App);
//sync(store. router);
app.use(router);
app.use(store);
app.use(new LoginValidations);
//app.use(UserController);
app.mount('#app');