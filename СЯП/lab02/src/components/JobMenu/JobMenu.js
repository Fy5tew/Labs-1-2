import React from 'react';
import JobMenuSelect from './JobMenuSelect';
import JobMenuLinks from './JobMenuLinks';
import './JobMenu.css';


const JOB_PLACEHOLDER = {
    id: 0,
    special: true,
    title: "...",
    links: [],
}


class JobMenu extends React.Component {
    constructor(props) {
        super(props);
        this.state = {currentJobId: JOB_PLACEHOLDER.id};
        this.setCurrentJob = this.setCurrentJob.bind(this);
    }

    setCurrentJob(jobId) {
        this.setState({currentJobId: jobId});
    }

    getJobs() {
        return [JOB_PLACEHOLDER, ...this.props.jobs];
    }

    render() {
        const jobs = this.getJobs();
        return (
            <div className="job-menu">
                <h3>Полезные ссылки для профессий</h3>
                <JobMenuSelect jobs={jobs} currentJobId={this.state.currentJobId} setJob={this.setCurrentJob} />
                <JobMenuLinks jobs={jobs} currentJobId={this.state.currentJobId} />
            </div>
        )
    }
}

export default JobMenu;
