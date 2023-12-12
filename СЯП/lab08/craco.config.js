const path = require('path');
// @ts-ignore
const jsconfig = require('./jsconfig.json');


const removeAsterisk = path => path.replace('/*', '');
const jestAliasKey = path => `^${path}(.*)$`;
const jestAliasValue = path => `<rootDir>/${path}$1`


const aliasProps = Object.entries(jsconfig.compilerOptions.paths).map(([key, value]) => {
    const newKey = removeAsterisk(key);
    let newValue = removeAsterisk(value[0]);
    newValue = path.resolve(__dirname, newValue);
    return [newKey, newValue];
})

const webpackAlias = Object.fromEntries(aliasProps)

const jestAlias = Object.fromEntries(aliasProps.map(([key, value]) => {
    const newKey = jestAliasKey(key);
    const newValue = jestAliasValue(value);
    return [newKey, newValue];
}))


module.exports = {
    webpack: {
        alias: webpackAlias,
    },
    jest: {
        configure: {
            moduleNameMapper: jestAlias,
        }
    }
}
