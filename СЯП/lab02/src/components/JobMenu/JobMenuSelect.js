function JobMenuOption({job}) {
    return (
        <option value={job.id} disabled={job.special} selected={job.special}>
            {job.title}
        </option>
    );
}


function JobMenuSelect({jobs, currentJobId, setJob}) {
    return (
        <div className="job-menu__select-wrapper">
            <span>Выберите профессию:</span>
            <select className="job-menu__select" onChange={e => setJob(+e.target.value)}>
                {
                    jobs.map((job, i) => <JobMenuOption key={i} job={job} />)
                }
            </select>
        </div>
    );
}


export default JobMenuSelect;
