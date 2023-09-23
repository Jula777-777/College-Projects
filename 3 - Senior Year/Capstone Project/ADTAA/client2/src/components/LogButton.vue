<template>
    <button @click="handleClick" :class="[dark ? 'dark' : 'light', 'baseButton']">{{ buttonText }}</button>
</template>

<script>
export default ({
    props: {
        buttonText: {
            type: String,
            default: () => "Label",
        },
    dark: {
        type: Boolean,
        default: () => false,
    },
    },
    methods: {
        handleClick() {
            console.log("hello")
        },
    },
});
</script>
