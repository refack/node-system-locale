module.exports = {
  name: getSystemLocaleName
}

var get_system_locale_name = require('../build/Release/get_system_locale_name')

/**
 * @param cb Function(err, systemLocaleName)
 */
function getSystemLocaleName(cb) {
  if (typeof cb !== 'function') {
    return
  }

  var systemLocaleName = get_system_locale_name()

  if (null == systemLocaleName) {
    var err = new Error('CannotDetermineSystemLocale')
    err.message = 'Cannot determine system locale'
    cb(err)
  } else {
    cb(null, parseLocaleName(systemLocaleName))
  }
}


//
// PRIVATE
//


/**
 * POSIX specifies the following format:
 *   [language[_territory][.codeset][@modifier]]
 */
var LOCALE_NAME_REGEXP = /^([a-zA-Z]+)(_[a-zA-Z]+)?(\.[a-zA-Z0-9_-]+)?(@[a-zA-Z0-9]+)?$/

/**
 * Parses `localeName` as a POSIX locale.
 */
function parseLocaleName(localeName) {
  var res = {
    locale: localeName
  }
  var m = localeName.match(LOCALE_NAME_REGEXP)
  if (null != m) {
    m.shift()
    res.language = m.shift()
    while (m.length > 0) {
      var val = m.shift()
      if (null == val) {
        continue
      }
      switch (val[0]) {
        case '_':
          res.territory = val.substr(1)
          break
        case '.':
          res.codeset = val.substr(1)
          break
        case '@':
          res.modifier = val.substr(1)
          break
        default:
          // Ignore...
          break
      }
    }
  }
  return res
}
