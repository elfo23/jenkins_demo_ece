def postAction

pipeline 
{
    agent any 
    
    stages 
    {
        stage ('init')
        {
            steps 
            {
                postAction = load 'postActions.groovy'
            }
        }
        stage('build') 
        {
            steps 
            {
                echo 'Build stage: compile all code and build an executable' 
                sh 'make'
            }
        }
        stage('test') 
        {
            steps 
            {
                echo 'Test stage: run the test cases' 
               	sh 'build/stack_test'
            }
        }
        stage('static-analysis') 
        {
            steps 
            {
                echo 'Static-analysis stage: run the cppcheck tool' 
               	sh 'cppcheck --enable=all --suppress=missingIncludeSystem src/*.c test/*.c '
            }
        }
    }

    post
    {
        always
        {
            postAction.alwaysPostAction()
        }
        failure
        {
            postAction.failurePostAction()
            emailext body: "${currentBuild.currentResult}: Job ${env.JOB_NAME} build ${env.BUILD_NUMBER}\n More info at: ${env.BUILD_URL}",
                subject: "Jenkins Build ${currentBuild.currentResult}: Job ${env.JOB_NAME}",
                to: 'philipp.steinwender@edu.fh-joanneum.at'

            //mail to: team@example.com, subject: 'The Pipeline failed :('
        }
        success
        {
            postAction.successPostAction()
        }
    }
}
