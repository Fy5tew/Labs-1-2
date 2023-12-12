function JobsMenuLink({link}) {
    return (
        <li className="job-menu__link">
            <a href={link.url} target="_blank">{link.title}</a>
        </li>
    );
}


function JobsMenuLinks({currentJobId, jobs}) {
    const job = jobs.find(job => job.id == currentJobId);
    if (!job.links.length) {
        return (
            <div className="job-menu__links-wrapper">
                <h4>
                    {
                        job.special
                            ? "Выберите профессию"
                            : `Для профессии «${job.title}» нет доступных ссылок`
                    }
                </h4>
            </div>
        );
    }
    return (
        <div className="job-menu__links-wrapper">
            <h4>Ссылки для профессии «{job.title}»:</h4>
            <ul className="job-menu__links">
                {
                    job.links.map((link, i) => <JobsMenuLink key={i} link={link} />)
                }
            </ul>
        </div>
    );
}


export default JobsMenuLinks;
