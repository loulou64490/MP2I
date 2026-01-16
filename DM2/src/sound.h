#pragma once

extern unsigned BITS;
extern unsigned SAMPLE_RATE;
extern double DEFAULT_LENGTH;
extern double DEFAULT_FREQUENCY;
extern double DEFAULT_AMPLITUDE;
extern double DEFAULT_ATTACK;
extern double DEFAULT_DECAY;
extern double DEFAULT_SUSTAIN;
extern double DEFAULT_RELEASE;

typedef struct sound {
  unsigned n_samples; // nombre d'échantillons
  short *samples;     // tableau des échantillons
} sound_t;

/*libère un élément sound_t* */
void free_sound(sound_t *sound);

typedef struct track {
  unsigned n_sounds; // nombre de son dans la piste
  sound_t **sounds;  // liste des sons
} track_t;

/*libère un élément track_t* */
void free_track(track_t *track);

/* transforme une piste en un unique son */
sound_t *reduce_track(track_t *track);

typedef struct mix {
  unsigned n_tracks; // nombre de pistes
  track_t **tracks;  // liste des pistes
  double *vols;      // liste des volumes des pistes
} mix_t;

/*libère un élément mix_t* */
void free_mix(mix_t *mix);

/* transforme un mix en son */
sound_t *reduce_mix(mix_t *mix);
