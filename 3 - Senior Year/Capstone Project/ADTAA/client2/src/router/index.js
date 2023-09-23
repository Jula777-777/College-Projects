import Vue from 'vue'
import VueRouter from 'vue-router'
import Index from '../views/Index.vue'

Vue.use(VueRouter)

const routes = [
  {
    path:'/',
    name:'HomePage',
    component: Index
  },
  {
    path: '/homepage',
    name: 'HomePage',
    component: Index
  },
  {
    path: '/login',
    name: 'LoginPage',
    component: () => import('../views/Login.vue')
  },
  {
    path: '/register',
    name: 'RegisterPage',
    component: () => import('../views/Register.vue')
  },
  {
    path: '/myschedule',
    name: 'SchedulePage',
    component: () => import('../views/MySchedule.vue'),
/*     meta: {
      requiresRole2Or3or4: true
    } */
  },
  {
    path: '/rootuserpage',
    name: 'RootUserPage',
    component: () => import('../views/RootUserPage.vue'),
    meta: {
      requiresRole4: true
    }
  },
  {
    path: '/setup',
    name: 'SetupPage',
    component: () => import('../views/Setup.vue'),
  /*   meta: {
      requiresRole3or4: true
    } */
  }
  
]

const router = new VueRouter({
  mode: 'history',
  base: process.env.BASE_URL,
  routes
})

export default router
