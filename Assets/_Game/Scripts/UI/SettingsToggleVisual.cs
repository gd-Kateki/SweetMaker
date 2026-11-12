using TMPro;
using UnityEngine;
using UnityEngine.UI;

public sealed class SettingsToggleVisual : MonoBehaviour
{
    [SerializeField] private Toggle toggle;
    [SerializeField] private Image trackImage;
    [SerializeField] private RectTransform knobRectTransform;
    [SerializeField] private Image knobImage;
    [SerializeField] private TMP_Text stateLabel;
    [SerializeField] private Vector2 onKnobPosition;
    [SerializeField] private Vector2 offKnobPosition;
    [SerializeField] private Color onTrackColor =
        new Color(0.52f, 0.31f, 0.66f, 1f);
    [SerializeField] private Color offTrackColor =
        new Color(0.56f, 0.54f, 0.51f, 1f);
    [SerializeField] private Color knobColor = Color.white;
    [SerializeField] private Color onLabelColor = Color.white;
    [SerializeField] private Color offLabelColor =
        new Color(0.12f, 0.08f, 0.14f, 1f);

    private bool reportedMissingReferences;

    private void OnEnable()
    {
        if (toggle != null)
        {
            toggle.onValueChanged.RemoveListener(HandleToggleValueChanged);
            toggle.onValueChanged.AddListener(HandleToggleValueChanged);
        }

        RefreshVisual();
    }

    private void OnDisable()
    {
        UnregisterToggleListener();
    }

    private void OnDestroy()
    {
        UnregisterToggleListener();
    }

    public void RefreshVisual()
    {
        if (toggle == null ||
            trackImage == null ||
            knobRectTransform == null ||
            knobImage == null ||
            stateLabel == null)
        {
            if (!reportedMissingReferences)
            {
                Debug.LogError(
                    "SettingsToggleVisual is missing one or more serialized references.",
                    this);
                reportedMissingReferences = true;
            }

            return;
        }

        bool isOn = toggle.isOn;
        trackImage.color = isOn ? onTrackColor : offTrackColor;
        knobImage.color = knobColor;
        knobRectTransform.anchoredPosition =
            isOn ? onKnobPosition : offKnobPosition;
        stateLabel.text = isOn ? "ON" : "OFF";
        stateLabel.color = isOn ? onLabelColor : offLabelColor;
    }

    public void ApplyAppearance(
        Sprite trackSprite,
        Sprite knobSprite,
        Color labelColor)
    {
        onTrackColor = Color.white;
        offTrackColor = Color.white;
        knobColor = Color.white;
        onLabelColor = labelColor;
        offLabelColor = labelColor;

        if (trackImage != null)
            trackImage.sprite = trackSprite;
        if (knobImage != null)
            knobImage.sprite = knobSprite;
        if (knobRectTransform != null)
            knobRectTransform.sizeDelta = new Vector2(72f, 72f);

        RefreshVisual();
    }

    private void HandleToggleValueChanged(bool _)
    {
        RefreshVisual();
    }

    public void ApplyCompactAppearance(Sprite surface)
    {
        onTrackColor = new Color(0.32f, 0.64f, 0.45f);
        offTrackColor = new Color(0.56f, 0.53f, 0.61f);
        knobColor = onLabelColor = offLabelColor = Color.white;
        onKnobPosition = new Vector2(42, 0);
        offKnobPosition = new Vector2(-42, 0);
        if (trackImage != null) { trackImage.sprite = surface; trackImage.type = Image.Type.Sliced; }
        if (knobImage != null) { knobImage.sprite = surface; knobImage.type = Image.Type.Sliced; }
        if (knobRectTransform != null)
        {
            knobRectTransform.anchorMin = knobRectTransform.anchorMax = new Vector2(.5f, .5f);
            knobRectTransform.sizeDelta = new Vector2(48, 48);
        }
        if (stateLabel != null)
        {
            // The moving knob conveys state without overlapping an ON/OFF label.
            stateLabel.gameObject.SetActive(false);
        }
        RefreshVisual();
    }

    private void UnregisterToggleListener()
    {
        if (toggle != null)
            toggle.onValueChanged.RemoveListener(HandleToggleValueChanged);
    }
}
