# system-locale

I was unable to figure out how to get locale information from within a node
process (such as Atom) and decided to bite the bullet and wrap
`std::setlocale(LC_ALL, "")` into this package.

# Questions

 *  Does this work on Windows at all?

# Notes

 *  Manually tested (i.e., executed examples) with node `v0.10.{5,12,26}` and
    `v0.11.13`.
