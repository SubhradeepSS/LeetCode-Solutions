const fs = require('fs')
const leetcode_url = "https://www.leetcode.com"
const repo_url = "https://github.com/SubhradeepSS/LeetCode-Solutions/blob/master"

let readme = "# LeetCode Solutions\n\n | Problem | Solution |\n| --- | --- |\n"

let directories;
fs.readFile('directories.json', (err, directory) => {
    directories = JSON.parse(directory)

    fs.readFile('problems.json', (err, data) => {
        if (err) {
            throw err
        }
        data = JSON.parse(data)
    
        data.forEach((problem, idx) => {
            readme += `| [${problem.title}](${leetcode_url}/problems/${problem.titleSlug}/) | [${problem.lang}](${repo_url}${directories[idx]})\n`
            fs.writeFileSync('README.md', readme)
        })
    })
})