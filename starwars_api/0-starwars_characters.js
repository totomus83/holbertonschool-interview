#!/usr/bin/node

const request = require('request');

const filmId = process.argv[2];
const url = `https://swapi-api.hbtn.io/api/films/${filmId}/`;

request(url, (err, res, body) => {
  if (err) return;

  const data = JSON.parse(body);
  const characters = data.characters;

  const printCharacter = (index) => {
    if (index >= characters.length) return;

    request(characters[index], (error, response, bodyChar) => {
      if (!error) {
        const characterData = JSON.parse(bodyChar);
        console.log(characterData.name);
      }
      printCharacter(index + 1);
    });
  };

  printCharacter(0);
});
