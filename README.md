# Jenkins Pipeline for C/C++ Applications
Copied from: https://github.com/teiniker/jenkins-pipeline-c 
## Setup
```
    $ sudo apt update
    $ sudo apt -y upgrade

    Jenkins Debian Packages
    https://pkg.jenkins.io/debian-stable/

    $ curl -fsSL https://pkg.jenkins.io/debian-stable/jenkins.io.key | sudo tee \
        /usr/share/keyrings/jenkins-keyring.asc > /dev/null

    $ echo deb [signed-by=/usr/share/keyrings/jenkins-keyring.asc] \
        https://pkg.jenkins.io/debian-stable binary/ | sudo tee \
        /etc/apt/sources.list.d/jenkins.list > /dev/null

    $ sudo apt-get update
    $ sudo apt-get install fontconfig openjdk-11-jre
    $ sudo apt-get install jenkins
```

Per default **Jenkins is running as a service** which is **enabled on system start**.
```
	$ systemctl status jenkins.service
	● jenkins.service - Jenkins Continuous Integration Server
		Loaded: loaded (/lib/systemd/system/jenkins.service; enabled; vendor preset: enabled)
		Active: active (running) since Sun 2022-05-01 12:04:49 CEST; 5h 33min ago
	    Main PID: 54753 (java)
		Tasks: 40 (limit: 4663)
		Memory: 506.4M
			CPU: 1min 40.953s
		CGroup: /system.slice/jenkins.service
				└─54753 /usr/bin/java -Djava.awt.headless=true -jar /usr/share/java/jenkins.war --webroot=/var/cache/jenkins/war --httpPort=8080
```


To **disable the service** and **manually start** it if needed, type:
```
$ sudo systemctl disable jenkins.service

$ sudo systemctl start jenkins.service
```



## Jenkins Job Configuration


## Jenkins Pipeline Syntax

A pipeline is a sequence of automated operations that usually represents a part of the software delivery and quality assurance process.

A Jenkins pipeline consists of two kinds of elements:
* **Step**: A single operation that tells Jenkins what to do.
	For example, check out code from the repository, execute a script .
* **Stage**: A logical separation of steps that groups conceptually distinct sequences of steps.
 	For example, Build, Test, and Deploy, used to visualize the Jenkins pipeline progress.

_Example_: Jenkins commit pipeline (checkout, build, and unit test)
```
pipeline 
{
    agent any 
    
    stages 
    {
        stage('build') 
        {
            steps 
            {
                sh 'make'
            }
        }
        stage('test') 
        {
            steps 
            {
               	sh 'build/stack_test'
            }
        }
    }
}
```

A **declarative pipeline** is always specified inside the `pipeline` block and contains sections, directives, and steps.

**Sections** define the pipeline structure and usually contain one or more directives or steps. They are defined with the following keywords: 

* **Stages**: This defines a series of one or more stage directives.

* **Steps**: This defines a series of one or more step instructions.

* **Post**: This defines a series of one or more step instructions that are run at the end of the pipeline build; they are marked with a condition (for example, always, success, or failure), and usually used to send notifications after the pipeline build (we will cover this in detail in the Triggers and notifications section).


**Directives** express the configuration of a pipeline or its parts: 

* **Agent**: This specifies where the execution takes place and can define the label to match the equally-labeled agents, or docker to specify a container that is dynamically provisioned to provide an environment for the pipeline execution. 

* **Triggers**: This defines automated ways to trigger the pipeline and can use cron to set the time-based scheduling, or pollSCM to check the repository for changes (we will cover this in detail in the Triggers and notifications section).

* **Options**: This specifies pipeline-specific options, for example, timeout (maximum time of pipeline run) or retry (number of times the pipeline should be re-run after failure).

* **Environment**: This defines a set of key values used as environment variables during the build.

* **Parameters**: This defines a list of user-input parameters.

* **Stage**: This allows for the logical grouping of steps.

* **When**: This determines whether the stage should be executed depending on the given condition.

### Steps 

Steps define the operations that are executed, so they actually tell Jenkins what to do: 

* **sh**: This executes the shell command; actually, it's possible to define almost any operation using `sh`. 

* **custom**: Jenkins offers a lot of operations that can be used as steps (for example, `echo`); many of them are simply wrappers over the sh command used for convenience; plugins can also define their own operations.

* **script**: This executes a block of the Groovy-based code that can be used for some non-trivial scenarios where flow control is needed.


## Commit Pipeline

The most **basic Continuous Integration process** is called a commit pipeline.

This phase starts with a commit (or push in Git) to the main repository and results in a report about 
the build success or failure. 

Since it runs after each change in the code, **the build should take no more than five minutes** and 
should consume a reasonable amount of resources.

The commit phase works as follows: a developer checks in the code to the repository, the Continuous Integration server detects the change, and the build starts. 
The most fundamental commit pipeline contains three stages: 
* **Checkout**: This stage downloads the source code from the repository. 

* **Compile**: This stage compiles the source code. 

* **Unit test**: This stage runs a suite of unit tests.





## References

* [YouTube: How to Install Jenkins](https://youtu.be/CEyfsQq3QEM)
* [YouTube: Complete Jenkins Pipeline Tutorial](https://youtu.be/7KCS70sCoK0)

* [Getting started with Pipeline](https://www.jenkins.io/doc/book/pipeline/getting-started/)

* [Using a Jenkinsfile](https://www.jenkins.io/doc/book/pipeline/jenkinsfile/)

* Rafał Leszko. **Continuous Delivery with Docker and Jenkins: Create secure applications by building complete CI/CD pipelines**. Packt Publishing, 2nd Edition 2019.

*Egon Teiniker, 2022, GPL v3.0* 
		
