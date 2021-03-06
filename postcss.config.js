const production = process.env.NODE_ENV === 'production';

const substitutions = {
  dist: production ? '' : '/dist/'
};

module.exports = {
  map: !production,
  plugins: {
    'postcss-import': {},

    'postcss-replace': {
      pattern: '{{\\s?([^\\s]+?)\\s?}}', // {{ something }}
      data: substitutions
    },

    'postcss-preset-env': {
      autoprefixer: { add: false },
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
