import {createRouter, createWebHistory } from 'vue-router';
import Login from './pages/Login.vue';
import Register from './pages/Register.vue';
import HomePage from './pages/HomePage.vue';
import MySchedule from './pages/MySchedule.vue';
import RootUserPage from './pages/RootUserPage.vue';
import Setup from './pages/Setup.vue';

const routes = [
    { path: '/login', component: Login},
    { path: '/register', component: Register},
    { path: '/homepage', component: HomePage},
    { path: '/myschedule', component: MySchedule},
    { 
        path: '/rootuserpage',
        component: RootUserPage
    },
    { 
        path: '/setup',
        component: Setup
    },
];

const router = createRouter({
    history: createWebHistory(),
    routes,
});

export default router;