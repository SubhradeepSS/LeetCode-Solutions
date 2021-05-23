const fs = require('fs')
let code_directories = []

fs.readFile('problems.json', (err, problems) => {
    problems = JSON.parse(problems)

    problems.forEach(problem => {
        const directory = __dirname + `/${problem.lang == 'python3' ? 'python' : problem.lang}`
        if (!fs.existsSync(directory)) {
            fs.mkdirSync(directory)
        }

        let fileExtension;
        switch (problem.lang) {
            case 'python3':
            case 'python':
                fileExtension = 'py'
                break

            case 'mysql':
                fileExtension = 'sql'
                break

            case 'bash':
                fileExtension = 'sh'
                break

            default:
                fileExtension = problem.lang
                break
        }

        const filePath = directory + `/${problem.title}.${fileExtension}`

        code_directories.push(`/${problem.lang == 'python3' ? 'python' : problem.lang}/${problem.title}.${fileExtension}`)

        fs.writeFileSync(filePath, problem.code)
    })
    fs.writeFileSync('directories.json', JSON.stringify(code_directories))
})