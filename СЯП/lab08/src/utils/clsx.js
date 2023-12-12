export const clsx = (...classes) => {
    return (
        classes
            .map(cls => cls.trim())
            .join(" ")
    );
}
