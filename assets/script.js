const buttons = document.querySelectorAll(".card-buttons button");
const sections = document.querySelectorAll(".list");
const card = document.querySelector(".card");

const ButtonClick = (e) => {
  const targetSection = e.target.getAttribute("data-section");
  const section = document.querySelector(targetSection);
  targetSection !== "#about" ? card.classList.add("active") : card.classList.remove("active");
  card.setAttribute("data-state", targetSection);
  sections.forEach((s) => s.classList.remove("active"));
  buttons.forEach((b) => b.classList.remove("active"));
  e.target.classList.add("active");
  section.classList.add("active");
};

buttons.forEach((btn) => btn.addEventListener("click", ButtonClick));
