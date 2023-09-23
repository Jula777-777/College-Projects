import Vue from 'vue'
import App from './App.vue'
import router from './router'
import store from './store'
import axios from 'axios'
import 'bootstrap'
import 'bootstrap/dist/css/bootstrap.min.css'

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
  if (to.matched.some(record => record.meta.requiresRole2Or3or4)) {
    if (localStorage.getItem('role') != 2 || localStorage.getItem('role') != 3 || localStorage.getItem('role') != 4) {
      next({
        path: '/'
      })
    } else {
      console.log("I was taken here")
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

Vue.config.productionTip = false


new Vue({
  router,
  store,
  render: h => h(App)
}).$mount('#app')
