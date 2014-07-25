# system-locale

I was unable to figure out how to get locale information from within a node
process (such as Atom) and decided to bite the bullet and wrap
`std::setlocale(LC_ALL, "")` into this package.

# API

There is only one (read-only) property, `name`.

```javascript
console.log(JSON.stringify(systemLocale.name, null, 2))
```

```json
$ locale
LANG="ja_JP.UTF-8"
LC_COLLATE="ja_JP.UTF-8"
LC_CTYPE="ja_JP.UTF-8"
LC_MESSAGES="ja_JP.UTF-8"
LC_MONETARY="ja_JP.UTF-8"
LC_NUMERIC="ja_JP.UTF-8"
LC_TIME="ja_JP.UTF-8"
LC_ALL=
$ node examples/simple.js
{
  "locale": "ja_JP.UTF-8",
  "language": "ja",
  "territory": "JP",
  "codeset": "UTF-8"
}
```

# Questions

 *  Does this work on Windows at all?

# Notes

 *  Manually tested (i.e., executed examples) with node `v0.10.{5,12,26}` and
    `v0.11.13`.
