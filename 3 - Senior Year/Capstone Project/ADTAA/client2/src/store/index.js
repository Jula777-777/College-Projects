import Vue from 'vue'
import Vuex from 'vuex'
import { VuexPersistence } from 'vuex-persist';
import auth from './auth'

Vue.use(Vuex)

const vuexLocalStorage = new VuexPersistence({
  key: 'state.adtaa',
  storage: window.localStorage
})

export default new Vuex.Store({
  modules: {
    auth
  },
  
plugins: [vuexLocalStorage.plugin]

})
