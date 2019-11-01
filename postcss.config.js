const production = process.env.NODE_ENV === 'production';

module.exports = {
  map: !production,
  plugins: {
    'postcss-import': {},

    'postcss-preset-env': {
      features: {
        'custom-properties': { preserve: false },
        'nesting-rules': true,
        'custom-media-queries': true
      }
    },

    'cssnano': production && {
      preset: ['default', {
        discardComments: { removeAll: true }
      }]
    }
  }
}
